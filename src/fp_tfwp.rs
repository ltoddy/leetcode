// LCR 112. 矩阵中的最长递增路径 (Hard)
// https://leetcode.cn/problems/fpTFWP/

struct Solution;

impl Solution {
    pub fn longest_increasing_path(matrix: Vec<Vec<i32>>) -> i32 {
        if matrix.is_empty() {
            return 0;
        }

        let mut coordinates = Vec::<(i32, i32)>::new();
        for i in 0..matrix.len() {
            for j in 0..matrix[i].len() {
                coordinates.push((i as i32, j as i32));
            }
        }

        let mut memo = vec![vec![0; matrix[0].len()]; matrix.len()];
        let mut path_lengths = Vec::<i32>::with_capacity(coordinates.len());

        for i in 0..matrix.len() {
            for j in 0..matrix[i].len() {
                let max_path = Self::dfs(&matrix, &mut memo, (i as i32, j as i32));
                path_lengths.push(max_path);
            }
        }

        path_lengths.into_iter().max().unwrap_or_default()
    }

    pub fn dfs(matrix: &Vec<Vec<i32>>, memo: &mut Vec<Vec<i32>>, pos: (i32, i32)) -> i32 {
        let cached = memo[pos.0 as usize][pos.1 as usize];
        if cached != 0 {
            return cached;
        }

        let directions = vec![(0, 1), (0, -1), (1, 0), (-1, 0)];
        let rows = matrix.len() as i32;
        let cols = matrix[0].len() as i32;
        let cur_val = matrix[pos.0 as usize][pos.1 as usize];

        let mut max_path = 1;
        for (dr, dc) in directions {
            let nr = pos.0 + dr;
            let nc = pos.1 + dc;
            if nr >= 0 && nr < rows && nc >= 0 && nc < cols {
                let next_val = matrix[nr as usize][nc as usize];
                if cur_val < next_val {
                    max_path = max_path.max(Self::dfs(matrix, memo, (nr, nc)) + 1);
                    memo[pos.0 as usize][pos.1 as usize] = max_path;
                }
            }
        }
        max_path
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_example_1() {
        assert_eq!(Solution::longest_increasing_path(vec![vec![9, 9, 4], vec![6, 6, 8], vec![2, 1, 1]]), 4);
    }

    #[test]
    fn test_example_2() {
        assert_eq!(Solution::longest_increasing_path(vec![vec![3, 4, 5], vec![3, 2, 6], vec![2, 2, 1]]), 4);
    }

    #[test]
    fn test_example_3() {
        assert_eq!(Solution::longest_increasing_path(vec![vec![1]]), 1);
    }
}
