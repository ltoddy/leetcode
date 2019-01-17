impl Solution {
    pub fn stone_game(piles: Vec<i32>) -> bool {
        let mut dp = [[0; 510]; 510];

        for i in 0..piles.len() {
            dp[i][..piles.len()].clone_from_slice(&piles[..]);
        }

        for i in 2..=piles.len() {
            for j in 0..=(piles.len() - i) {
                let k = i + j - 1;
                dp[j][k] = (piles[j] - dp[j + 1][k]).max(piles[k] - dp[j][k - 1]);
            }
        }

        return dp[0][piles.len() - 1] > 0;
    }
}
