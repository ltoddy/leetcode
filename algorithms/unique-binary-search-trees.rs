impl Solution {
    pub fn num_trees(n: i32) -> i32 {
        let mut catalan = vec![0; (n + 1) as usize];
        catalan[0] = 1;
        catalan[1] = 1;
        for i in 2..=n {
            for j in 0..i {
                catalan[i as usize] += catalan[j as usize] * catalan[(i - j - 1) as usize];
            }
        }
        catalan[n as usize]
    }
}
