impl Solution {
    const NEXT: [(i32, i32); 4] = [(0, 1), (1, 0), (0, -1), (-1, 0)];

    fn dfs(grid: &mut Vec<Vec<char>>, i: i32, j: i32) {
        if (i < 0 || i >= (grid.len() as i32))
            || (j < 0 || j >= (grid[i as usize].len() as i32))
            || grid[i as usize][j as usize] == '0'
        {
            return;
        }

        grid[i as usize][j as usize] = '0';
        for (nx, ny) in &Self::NEXT {
            Self::dfs(grid, i + nx, j + ny);
        }
    }

    pub fn num_islands(grid: Vec<Vec<char>>) -> i32 {
        let mut grid = grid;

        let mut result = 0;
        for i in 0..grid.len() {
            for j in 0..grid[i].len() {
                if grid[i][j] == '1' {
                    result += 1;
                    Self::dfs(&mut grid, i as i32, j as i32);
                }
            }
        }
        result
    }
}
