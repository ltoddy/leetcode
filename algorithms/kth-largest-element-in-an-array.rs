impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums = nums;
        let k_pos = (k - 1) as usize;
        nums.sort_by(|prev, cur| {
            if prev > cur {
                return std::cmp::Ordering::Less;
            } else if prev < cur {
                return std::cmp::Ordering::Greater;
            } else {
                return std::cmp::Ordering::Equal;
            }
        });
        nums[k_pos]
    }
}
