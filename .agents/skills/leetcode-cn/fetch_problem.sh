#!/bin/bash
# 拉取 LeetCode CN 题目详情
# 用法: ./fetch_problem.sh <title_slug> [language]
# 示例: ./fetch_problem.sh two-sum
#       ./fetch_problem.sh two-sum rust  # 同时输出代码模板

set -euo pipefail

SLUG="${1:-}"
LANG="${2:-}"

if [ -z "$SLUG" ]; then
  echo "用法: $0 <title_slug> [language]"
  echo "示例: $0 two-sum"
  echo "      $0 two-sum rust"
  exit 1
fi

echo "> 正在拉取: $SLUG ..." >&2

QUERY='{"query":"query questionData($titleSlug: String!) { question(titleSlug: $titleSlug) { questionFrontendId title titleSlug difficulty translatedTitle translatedContent content codeDefinition metaData sampleTestCase exampleTestcases topicTags { name translatedName slug } } }","variables":{"titleSlug":"'"$SLUG"'"}}'

DATA=$(curl -s 'https://leetcode.cn/graphql/' \
  -H 'Content-Type: application/json' \
  -d "$QUERY")

# 检查错误
ERROR=$(echo "$DATA" | jq -r '.errors[0].message // empty')
if [ -n "$ERROR" ]; then
  echo "❌ API 错误: $ERROR" >&2
  exit 1
fi

Q=$(echo "$DATA" | jq -r '.data.question')
if [ "$Q" = "null" ]; then
  echo "❌ 未找到题目: $SLUG" >&2
  exit 1
fi

ID=$(echo "$Q" | jq -r '.questionFrontendId')
TITLE_CN=$(echo "$Q" | jq -r '.translatedTitle // ""')
TITLE_EN=$(echo "$Q" | jq -r '.title')
DIFFICULTY=$(echo "$Q" | jq -r '.difficulty')
TAGS=$(echo "$Q" | jq -r '.topicTags[]?.translatedName // .topicTags[]?.name' 2>/dev/null | paste -sd ',' - || echo "")

echo "📋 ${ID}. ${TITLE_CN:-$TITLE_EN} (${DIFFICULTY})" >&2
[ -n "$TAGS" ] && echo "🏷  ${TAGS}" >&2
echo "" >&2

# 输出题目描述
CONTENT=$(echo "$Q" | jq -r '.translatedContent // .content // ""')
if [ -n "$CONTENT" ]; then
  # 简单去除 HTML 标签，用 lynx 或 textutil 可做更好的转换
  echo "$CONTENT" | sed 's/<[^>]*>//g' | sed 's/&nbsp;/ /g' | sed 's/&lt;/</g' | sed 's/&gt;/>/g' | sed 's/&amp;/\&/g' | sed 's/&quot;/"/g' | sed 's/&#39;/'"'"'/g'
  echo ""
fi

# 输出代码模板（如果指定了语言）
if [ -n "$LANG" ]; then
  CODE_DEF=$(echo "$Q" | jq -r '.codeDefinition')
  CODE=$(echo "$CODE_DEF" | jq -r --arg lang "$LANG" '.[] | select(.value == $lang) | .defaultCode // empty')
  if [ -n "$CODE" ]; then
    echo "=== $LANG 代码模板 ===" >&2
    echo "$CODE"
  else
    echo "⚠️  未找到 $LANG 的代码模板" >&2
  fi
fi
