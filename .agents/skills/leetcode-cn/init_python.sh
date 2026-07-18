#!/bin/bash
# 初始化 LeetCode Python 题解到 solutions/ 目录
# 用法: ./init_python.sh <title_slug>
# 示例: ./init_python.sh two-sum

set -euo pipefail

SLUG="${1:-}"

if [ -z "$SLUG" ]; then
  echo "用法: $0 <title_slug>"
  echo "示例: $0 two-sum"
  exit 1
fi

FILE="solutions/${SLUG}.py"

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

# 2. 提取 Python3 代码模板
CODE_DEF=$(echo "$Q" | jq -r '.codeDefinition')
# LeetCode 中 Python 的 value 是 "python3"
CODE=$(echo "$CODE_DEF" | jq -r '.[] | select(.value == "python3") | .defaultCode // empty')

if [ -z "$CODE" ]; then
  echo "❌ 未找到 Python 代码模板"
  exit 1
fi

# 3. 写入文件 (空函数体自动注入 pass)
mkdir -p solutions

{
  echo "# ${ID}. ${TITLE} (${DIFFICULTY})"
  echo "# https://leetcode.cn/problems/${SLUG}/"
  echo ""
  echo "$CODE"
} > "$FILE"

# 在 class/def 定义行后插入 pass，使空函数体语法合法
python3 - "$FILE" << 'PYEOF'
import sys, re

path = sys.argv[1]
with open(path, 'r') as f:
    lines = f.readlines()

result = []
for line in lines:
    result.append(line)
    # 只匹配 def xxx(...): 在方法定义后插入 pass
    m = re.match(r'^( *)def .+:', line.rstrip('\n'))
    if m:
        indent = m.group(1) + '    '
        result.append(indent + 'pass\n')

with open(path, 'w') as f:
    f.writelines(result)
PYEOF

echo "✅ 已创建 $FILE"

# 4. 检查语法
echo ""
echo "> python3 -m py_compile ..."
if python3 -m py_compile "$FILE" 2>&1; then
  echo "✅ 语法检查通过"
else
  echo "⚠️  语法检查失败（待实现逻辑时正常）"
fi
