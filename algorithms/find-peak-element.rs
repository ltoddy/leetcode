impl Solution {
    pub fn find_peak_element(nums: Vec<i32>) -> i32 {
        if nums.len() == 1 {
            return 0;
        }

        if nums[0] > nums[1] {
            return 0;
        }

        for i in 1..(nums.len() - 1) {
            if nums[i] > nums[i - 1] && nums[i] > nums[i + 1] {
                return i as i32;
            }
        }

        (nums.len() - 1) as i32
    }
}
