impl Solution {
    pub fn single_non_duplicate(nums: Vec<i32>) -> i32 {
        nums.iter().fold(0, |acc, num| acc ^ num)
    }
}
