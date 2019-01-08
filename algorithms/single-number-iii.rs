impl Solution {
    pub fn single_number(nums: Vec<i32>) -> Vec<i32> {
        if nums.is_empty() {
            return vec![];
        }

        let mut xor = 0;
        for num in &nums {
            xor ^= num;
        }

        let diff = (xor & (xor - 1)) ^ xor;
        let mut a = 0;
        let mut b = 0;
        for num in &nums {
            if diff & num == 0 {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        return vec![a, b];
    }
}
