---
name: leetcode-cn
description: "Fetch problem content from leetcode.cn via GraphQL API. Use when you need to get problem descriptions, code templates, test cases, or problem lists from LeetCode China."
---

# LeetCode CN API

## 核心端点

- **GraphQL**: `https://leetcode.cn/graphql/` — 获取题目详情、题目列表、每日一题等
- **REST**: `https://leetcode.cn/api/problems/all/` — 获取全量题目列表（不含题目详情）

无需登录即可获取题目内容。

## When to use

- 获取指定题目的描述、代码模板、测试用例
- 浏览/搜索题目列表（按难度、标签筛选）
- 获取每日一题
- 初始化新题目到本地代码仓库

## 脚本

所有脚本位于 skill 目录下，可直接执行：

### `./fetch_problem.sh <title_slug> [language]`

拉取题目详情（编号、标题、难度、标签、描述、代码模板）。

```
./fetch_problem.sh two-sum          # 拉取题目信息
./fetch_problem.sh two-sum rust     # 同时输出 Rust 代码模板
```

### `./init_rust.sh <title_slug>`

一站式初始化 Rust 题解到 `src/` 目录：
- 拉取题目数据 + Rust 代码模板
- 自动注入 `struct Solution;` 和 `todo!()`
- 将 slug 中的 `-` 转为 `_`（Rust 模块名规范）
- 在 `src/lib.rs` 中注册模块声明（去重）
- 运行 `cargo check` 验证
- **注意：不会自动生成测试用例。初始化完成后，agent 应自行获取题目示例并添加测试代码（见下方「添加测试用例」章节）**

```
./init_rust.sh two-sum
./init_rust.sh number-of-music-playlists
```

### `./init_python.sh <title_slug>`

一站式初始化 Python 题解到 `solutions/` 目录：
- 拉取题目数据 + Python3 代码模板
- 在文件头部添加注释（编号、标题、难度、链接）
- 自动在 `def` 定义后注入 `pass`（避免空函数体语法错误）
- 运行 `python3 -m py_compile` 检查语法
- **注意：不会自动生成测试用例。初始化完成后，agent 应自行获取题目示例并添加测试代码（见下方「添加测试用例」章节）**

```
./init_python.sh two-sum
```

### `./get_daily.sh [--with-code lang]`

获取每日一题。

```
./get_daily.sh                    # 只显示题目信息
./get_daily.sh --with-code rust   # 同时输出代码模板
```

### `./list_problems.sh [--difficulty EASY|MEDIUM|HARD] [--limit N] [--random]`

列出题目。

```
./list_problems.sh                          # 前 50 道
./list_problems.sh --difficulty HARD --limit 5       # 5 道 hard
./list_problems.sh --difficulty MEDIUM --random      # 随机 medium
```

## API 参考

### GraphQL 核心查询

```graphql
query questionData($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    questionId questionFrontendId title titleSlug difficulty
    translatedTitle translatedContent content
    codeDefinition        # JSON 字符串，需二次解析
    jsonExampleCodelets
    sampleTestCase exampleTestcases
    metaData              # JSON 字符串，函数签名/参数定义
    judgeType mysqlSchemas
    enableRunCode enableTestMode
    topicTags { name translatedName slug }
  }
}
```

### 关键字段说明

| 字段 | 说明 |
|------|------|
| `titleSlug` | URL 中的题目标识，如 `two-sum` |
| `translatedTitle` | 中文题目名 |
| `translatedContent` | 中文题目描述（HTML） |
| `content` | 英文题目描述（HTML） |
| `codeDefinition` | 各语言的代码模板（JSON 字符串） |
| `sampleTestCase` | 示例测试用例 |
| `exampleTestcases` | 示例测试用例（多行） |
| `metaData` | 函数签名/参数定义（JSON 字符串） |
| `topicTags` | 标签列表 |
| `difficulty` | 难度：Easy / Medium / Hard |

### 题目列表（REST）

```bash
curl -s 'https://leetcode.cn/api/problems/all/' | jq '.stat_status_pairs[] | {id: .stat.frontend_question_id, title: .stat.question__title, slug: .stat.question__title_slug, difficulty: .difficulty.level}'
```

### 每日一题（GraphQL）

```graphql
query questionOfToday {
  todayRecord { date question { titleSlug title translatedTitle difficulty } }
}
```

## 添加测试用例

`init_rust.sh` 和 `init_python.sh` 不会自动生成测试用例。初始化后，agent 应：

1. 通过 GraphQL 查询题目数据（含 `exampleTestcaseList`、`metaData`、`translatedContent`）
2. 解析示例的输入和期望输出
3. 直接编辑文件添加测试代码

**Rust 测试格式：**

```rust
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_example_1() {
        assert_eq!(Solution::method(args...), expected);
    }

    #[test]
    fn test_example_2() {
        assert_eq!(Solution::method(args...), expected);
    }
}
```

**Python 测试格式：**

```python
if __name__ == '__main__':
    s = Solution()
    assert s.method(args...) == expected
```

**类型转换规则：**
- LeetCode 数组 `[1,2,3]` → Rust `vec![1,2,3]`，Python `[1,2,3]`
- 矩阵 `[[1,2],[3,4]]` → Rust `vec![vec![1,2],vec![3,4]]`
- 字符串 `"abc"` → Rust `"abc".to_string()`，Python `"abc"`（不变）
- 函数名：LeetCode 的 `camelCase` 在测试中保持不变（匹配 Rust/Python 模板中的函数名）
- `metaData` 中 `params` 数组的 `type` 字段指示参数类型

## 初始化题目到代码仓库

### Rust（本项目）

从 LeetCode 拉取题目数据，创建 `src/<module_name>.rs`，并在 `lib.rs` 中注册模块。

直接使用 `./init_rust.sh <title_slug>` 即可。

### Python

从 LeetCode 拉取题目数据，创建 `solutions/<slug>.py`。

直接使用 `./init_python.sh <title_slug>` 即可。

### 其他语言目录约定

| 语言 | 文件路径 | 备注 |
|------|---------|------|
| Rust | `src/<slug>.rs` | 需在 `lib.rs` 中声明 `mod <slug>;` |
| Python | `solutions/<slug>.py` | — |
| TypeScript | `solutions/<slug>.ts` | — |
| Go | `solutions/<slug>/solution.go` | 每个题目一个 package |
| Java | `src/main/java/<slug>/Solution.java` | — |
| C++ | `algorithms/<slug>.cpp` | — |

## Rust 注意事项

1. **`struct Solution;`**: LeetCode 的 Rust 模板只包含 `impl Solution`，编译到本地 crate 时需要手动添加
2. **Slug 转模块名**: URL slug 使用 `-` 分隔（如 `number-of-music-playlists`），Rust 模块名必须用 `_`（`number_of_music_playlists`）
3. **`todo!()`**: 创建文件后填入 `todo!()` 宏，避免空函数体导致类型错误

`init_rust.sh` 已自动处理以上三点。

## Notes

- `titleSlug` 可以从题目 URL 中获取：`https://leetcode.cn/problems/<titleSlug>/`
- GraphQL 返回的 `content`/`translatedContent` 是 HTML 格式
- `codeDefinition` 和 `metaData` 是 JSON 字符串，需要二次解析
- 提交代码等写操作需要登录态（cookie），本 skill 仅覆盖读操作
- 请求频率过高可能触发限流，建议适当间隔
