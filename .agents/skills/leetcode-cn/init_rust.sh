#!/bin/bash
# 初始化 LeetCode Rust 题解到 src/ 目录
# 用法: ./init_rust.sh <title_slug>
# 示例: ./init_rust.sh two-sum
#       ./init_rust.sh number-of-music-playlists

set -euo pipefail

SLUG="${1:-}"

if [ -z "$SLUG" ]; then
  echo "用法: $0 <title_slug>"
  echo "示例: $0 two-sum"
  exit 1
fi

# 将 slug 转为合法的 Rust 模块名 (hyphen → underscore)
MOD_NAME="${SLUG//-/_}"
FILE="src/${MOD_NAME}.rs"

if [ -f "$FILE" ]; then
  echo "⚠️  文件已存在: $FILE，跳过"
  exit 0
fi

echo "> 拉取题目: $SLUG ..."

# 1. 拉取代码模板
QUERY='{"query":"query q($titleSlug: String!){question(titleSlug:$titleSlug){codeDefinition questionFrontendId translatedTitle difficulty}}","variables":{"titleSlug":"'"$SLUG"'"}}'

DATA=$(curl -s 'https://leetcode.cn/graphql/' \
  -H 'Content-Type: application/json' \
  -d "$QUERY")

Q=$(echo "$DATA" | jq -r '.data.question')
if [ "$Q" = "null" ]; then
  echo "❌ 未找到题目: $SLUG"
  exit 1
fi

ID=$(echo "$Q" | jq -r '.questionFrontendId')
TITLE=$(echo "$Q" | jq -r '.translatedTitle')
DIFFICULTY=$(echo "$Q" | jq -r '.difficulty')

echo "📋 ${ID}. ${TITLE} (${DIFFICULTY})"

# 2. 提取 Rust 代码模板
CODE_DEF=$(echo "$Q" | jq -r '.codeDefinition')
CODE=$(echo "$CODE_DEF" | jq -r '.[] | select(.value == "rust") | .defaultCode // empty')

if [ -z "$CODE" ]; then
  echo "❌ 未找到 Rust 代码模板"
  exit 1
fi

# 3. 写入文件 (注入 struct Solution + todo!())
mkdir -p src

{
  echo "// ${ID}. ${TITLE} (${DIFFICULTY})"
  echo "// https://leetcode.cn/problems/${SLUG}/"
  echo ""
  echo "struct Solution;"
  echo ""
  echo "$CODE" | python3 -c "
import sys, re
lines = sys.stdin.readlines()

# --- helper: uncomment TreeNode-like blocks ---
def is_code_comment(line):
    '''判断 // xxx 是否像注释掉的代码'''
    s = line.lstrip()[2:].lstrip()  # 去掉 // 及后续空白
    return bool(re.match(r'(pub\b|impl\b|struct\b|fn\b|enum\b|#\[)', s) or
                re.match(r'\s*(pub\s+)?(val|left|right|next)\s*:', s) or
                re.match(r'^\s*[A-Z]\w+\s*\{', s) or  # TreeNode {
                '{' in s or '}' in s or
                re.match(r'^\s*\w+\s*[,;]?\s*$', s))  # bare ident: val, right: None → handled above

def is_comment_line(line):
    return line.lstrip().startswith('//') and not line.lstrip().startswith('// ')

def uncomment_block(ls, start):
    # 跳过 // Definition for ... 注释头
    while start < len(ls) and ls[start].lstrip().startswith('// ') and not is_code_comment(ls[start]):
        start += 1
    i = start
    while i < len(ls):
        s = ls[i].lstrip()
        if s.startswith('// ') and is_code_comment(ls[i]):
            ls[i] = re.sub(r'^(\s*)// ', r'\1', ls[i])
        elif s in ('//', '//\n', '//\r\n'):
            pass  # 空注释分隔行，跳过继续
        else:
            break
        i += 1
    if i > start:
        ls.insert(i, '\n')
    return ls

i = 0
while i < len(lines):
    stripped = lines[i].lstrip()
    if stripped.startswith('//') and ('pub struct TreeNode' in stripped or '// Definition for' in stripped):
        lines = uncomment_block(lines, i)
    i += 1

# --- inject todo!() into empty function bodies ---
result = []
i = 0
while i < len(lines):
    result.append(lines[i])
    if re.search(r'^\s*pub\s+fn\s', lines[i]) and lines[i].rstrip().endswith('{'):
        depth = 1
        j = i + 1
        body_lines = []
        while j < len(lines) and depth > 0:
            body_lines.append(lines[j])
            s = lines[j].rstrip('\n').lstrip()
            if not s.startswith('//'):
                depth += s.count('{') - s.count('}')
            j += 1

        # 排除最后的 } ，检查其余行是否只有空白/注释
        non_empty = [l for l in body_lines[:-1] if l.strip() and not l.strip().startswith('//') and not l.strip().startswith('/*') and not l.strip().startswith('*')]
        if len(non_empty) == 0:
            indent = len(lines[i]) - len(lines[i].lstrip()) + 4
            result.append(' ' * indent + 'todo!()\n')
    i += 1

sys.stdout.writelines(result)
"
} > "$FILE"

echo "✅ 已创建 $FILE"

# 4. 在 lib.rs 中注册模块（去重）
if ! grep -qxF "mod ${MOD_NAME};" src/lib.rs 2>/dev/null; then
  echo "mod ${MOD_NAME};" >> src/lib.rs
  echo "✅ 已在 src/lib.rs 中添加 mod ${MOD_NAME};"
else
  echo "ℹ️  src/lib.rs 中已存在 mod ${MOD_NAME};"
fi

# 5. 编译验证
echo ""
echo "> cargo check ..."
if cargo check 2>&1; then
  echo "✅ 编译通过"
else
  echo "⚠️  编译有 warning（未实现逻辑时正常）"
fi
