use std::collections::VecDeque;

impl Solution {
    const NEXT: [(i32, i32); 4] = [(-1, 0), (1, 0), (0, -1), (0, 1)];

    pub fn oranges_rotting(grid: Vec<Vec<i32>>) -> i32 {
        let mut grid = grid;
        let mut queue = VecDeque::new();

        for (row, elements) in grid.iter().enumerate() {
            for (col, element) in elements.iter().enumerate() {
                if *element == 2 {
                    queue.push_back((row, col));
                }
            }
        }

        let mut time = 0;
        while !queue.is_empty() {
            if grid.iter().all(|row| !row.contains(&1)) {
                break;
            }

            let length = queue.len();
            for _ in 0..length {
                let (row, col) = queue.pop_front().unwrap();
                for (nx, ny) in Self::NEXT.iter() {
                    let x = row as i32 + *nx;
                    let y = col as i32 + *ny;
                    if (x >= 0 && x < grid.len() as i32)
                        && (y >= 0 && y < grid[0].len() as i32)
                        && grid[x as usize][y as usize] == 1
                    {
                        grid[x as usize][y as usize] = 2;
                        queue.push_back((x as usize, y as usize));
                    }
                }
            }
            time += 1;
        }

        if grid.iter().any(|row| row.contains(&1)) {
            return -1;
        }
        time
    }
}
