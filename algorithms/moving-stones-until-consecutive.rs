impl Solution {
    pub fn num_moves_stones(a: i32, b: i32, c: i32) -> Vec<i32> {
        let mut nums = vec![a, b, c];
        nums.sort();

        if nums[2] - nums[0] == 2 {
            return vec![0, 0];
        }

        let left = if (nums[1] - nums[0]).min(nums[2] - nums[1]) <= 2 {
            1
        } else {
            2
        };
        let right = nums[2] - nums[0] - 2;

        vec![left, right]
    }
}
