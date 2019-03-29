impl Solution {
    pub fn num_pairs_divisible_by60(time: Vec<i32>) -> i32 {
        const SECONDS: usize = 60;

        let mut total = 0;
        let mut records = vec![0; SECONDS];

        for t in time {
            total += records[(SECONDS - t as usize % SECONDS) % SECONDS];
            records[t as usize % SECONDS] += 1;
        }

        total
    }
}
