impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        for i in 0..32 {
            let mut sum = 0;
            for num in &nums {
                sum += (num >> i) & 1;
            }
            res |= (sum % 3) << i;
        }
        return res;
    }
}
