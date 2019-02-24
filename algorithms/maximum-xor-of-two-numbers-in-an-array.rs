impl Solution {
    pub fn find_maximum_xor(nums: Vec<i32>) -> i32 {
        let mut max = 0;
        for i in 0..nums.len() {
            for j in i..nums.len() {
                let num = nums[i] ^ nums[j];
                if num > max {
                    max = num
                }
            }
        }
        max
    }
}
