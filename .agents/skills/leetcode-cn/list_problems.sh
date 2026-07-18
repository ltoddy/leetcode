#!/bin/bash
# 列出 LeetCode CN 题目，支持按难度筛选
# 用法: ./list_problems.sh [--difficulty EASY|MEDIUM|HARD] [--limit N] [--random]
# 示例: ./list_problems.sh
#       ./list_problems.sh --difficulty HARD --limit 5
#       ./list_problems.sh --difficulty MEDIUM --random

set -euo pipefail

DIFFICULTY=""
LIMIT=50
RANDOM_MODE=false

while [[ $# -gt 0 ]]; do
  case "$1" in
    --difficulty)
      DIFFICULTY="${2:-}"
      shift 2
      ;;
    --limit)
      LIMIT="${2:-50}"
      shift 2
      ;;
    --random)
      RANDOM_MODE=true
      shift
      ;;
    *)
      echo "用法: $0 [--difficulty EASY|MEDIUM|HARD] [--limit N] [--random]"
      exit 1
      ;;
  esac
done

echo "> 正在拉取题目列表 ..." >&2

ALL=$(curl -s 'https://leetcode.cn/api/problems/all/')

# 构建 jq 筛选
JQ_FILTER='.stat_status_pairs[]'
if [ -n "$DIFFICULTY" ]; then
  case "$DIFFICULTY" in
    EASY)    LVL=1 ;;
    MEDIUM)  LVL=2 ;;
    HARD)    LVL=3 ;;
    *)       echo "❌ 无效难度: $DIFFICULTY (应为 EASY/MEDIUM/HARD)"; exit 1 ;;
  esac
  JQ_FILTER+=" | select(.difficulty.level == $LVL)"
fi

if $RANDOM_MODE; then
  echo "$ALL" | jq -r "[$JQ_FILTER] | .[] | [.stat.frontend_question_id, .stat.question__title_slug, .stat.question__title, .difficulty.level] | @tsv" \
    | sort -R | head -n "$LIMIT" \
    | awk -F'\t' '{
        lvl=$4;
        if(lvl==1) d="Easy";
        else if(lvl==2) d="Medium";
        else d="Hard";
        printf "%s. %s (%s) [%s]\n", $1, $3, d, $2
      }'
else
  echo "$ALL" | jq -r "[$JQ_FILTER] | .[:${LIMIT}] | .[] | [.stat.frontend_question_id, .stat.question__title_slug, .stat.question__title, .difficulty.level] | @tsv" \
    | awk -F'\t' '{
        lvl=$4;
        if(lvl==1) d="Easy";
        else if(lvl==2) d="Medium";
        else d="Hard";
        printf "%s. %s (%s) [%s]\n", $1, $3, d, $2
      }'
fi
