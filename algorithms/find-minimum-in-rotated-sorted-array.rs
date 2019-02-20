impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {
        nums.iter().skip(1).fold(nums[0], |acc, num| acc.min(*num))
    }
}
