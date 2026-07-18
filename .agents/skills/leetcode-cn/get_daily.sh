#!/bin/bash
# 获取 LeetCode CN 每日一题
# 用法: ./get_daily.sh [--with-code lang]

set -euo pipefail

WITH_CODE=false
LANG="rust"

while [[ $# -gt 0 ]]; do
  case "$1" in
    --with-code)
      WITH_CODE=true
      LANG="${2:-rust}"
      shift 2
      ;;
    *)
      echo "用法: $0 [--with-code lang]"
      echo "       $0              # 只显示题目信息"
      echo "       $0 --with-code rust  # 同时输出代码模板"
      exit 1
      ;;
  esac
done

QUERY='{"query":"query questionOfToday { todayRecord { date question { titleSlug title translatedTitle difficulty questionFrontendId } } }","variables":{}}'

DATA=$(curl -s 'https://leetcode.cn/graphql/' \
  -H 'Content-Type: application/json' \
  -d "$QUERY")

Q=$(echo "$DATA" | jq -r '.data.todayRecord[0]')
if [ "$Q" = "null" ]; then
  echo "❌ 无法获取每日一题"
  exit 1
fi

DATE=$(echo "$Q" | jq -r '.date')
ID=$(echo "$Q" | jq -r '.question.questionFrontendId')
TITLE_CN=$(echo "$Q" | jq -r '.question.translatedTitle')
TITLE_EN=$(echo "$Q" | jq -r '.question.title')
SLUG=$(echo "$Q" | jq -r '.question.titleSlug')
DIFFICULTY=$(echo "$Q" | jq -r '.question.difficulty')

echo "📅 每日一题 (${DATE})"
echo "📋 ${ID}. ${TITLE_CN:-$TITLE_EN} (${DIFFICULTY})"
echo "🔗 https://leetcode.cn/problems/${SLUG}/"

if $WITH_CODE; then
  echo ""
  echo "--- $LANG 代码模板 ---"
  CODE_DATA=$(curl -s 'https://leetcode.cn/graphql/' \
    -H 'Content-Type: application/json' \
    -d '{"query":"query q($s: String!){question(titleSlug:$s){codeDefinition}}","variables":{"titleSlug":"'"$SLUG"'"}}')
  echo "$CODE_DATA" | jq -r '.data.question.codeDefinition' | jq -r --arg lang "$LANG" '.[] | select(.value == $lang) | .defaultCode // empty'
fi
