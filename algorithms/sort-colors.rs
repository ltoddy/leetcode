impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let mut red_count: usize = 0;
        let mut white_count: usize = 0;
        let mut blue_count: usize = 0;

        for num in nums.iter() {
            let num = *num;
            if num == 0 {
                red_count += 1;
            } else if num == 1 {
                white_count += 1
            } else if num == 2 {
                blue_count += 1
            }
        }
        let mut index: usize = 0;
        for _ in 0..red_count {
            nums[index] = 0;
            index += 1;
        }
        for _ in 0..white_count {
            nums[index] = 1;
            index += 1;
        }
        for _ in 0..blue_count {
            nums[index] = 2;
            index += 1;
        }
    }
}
