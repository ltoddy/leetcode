impl Solution {
    pub fn game_of_life(board: &mut Vec<Vec<i32>>) {
        let next: Vec<(i32, i32)> = vec![(-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1)];

        for i in 0..board.len() {
            for j in 0..board[i].len() {
                let mut lives = 0;
                for (x, y) in &next {
                    let (nx, ny) = (i as i32 + x, j as i32 + y);
                    if (nx >= 0 && nx < board.len() as i32) && (ny >= 0 && ny < board[i].len() as i32) &&
                        (board[nx as usize][ny as usize] == 1 || board[nx as usize][ny as usize] == 2) {
                        lives += 1;
                    }
                }

                if board[i][j] > 0 && (lives < 2 || lives > 3) {
                    board[i][j] = 2;
                } else if board[i][j] == 0 && lives == 3 {
                    board[i][j] = 3;
                }
            }
        }

        for elements in board {
            for element in elements {
                *element %= 2;
            }
        }
    }
}
