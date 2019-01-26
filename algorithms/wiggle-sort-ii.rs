impl Solution {
    pub fn wiggle_sort(nums: &mut Vec<i32>) {
        let mut temp = nums.clone();
        temp.sort();

        let mut k = (nums.len() + 1) / 2;
        let mut j = nums.len();
        for (i, num) in nums.iter_mut().enumerate() {
            *num = if i & 1 == 1 {
                j -= 1;
                temp[j]
            } else {
                k -= 1;
                temp[k]
            };
        }
    }
}
