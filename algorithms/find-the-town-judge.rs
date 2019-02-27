impl Solution {
    pub fn find_judge(n: i32, trust: Vec<Vec<i32>>) -> i32 {
        let mut p1 = vec![0; n as usize + 1];
        let mut p2 = vec![0; n as usize + 1];

        for item in trust {
            p1[item[0] as usize] += 1;
            p2[item[1] as usize] += 1;
        }

        for i in 1..=(n as usize) {
            if p1[i] == 0 && p2[i] == n - 1 {
                return i as i32;
            }
        }

        -1
    }
}
