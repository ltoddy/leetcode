impl Solution {
    fn helper(result: &mut Vec<Vec<i32>>, start: i32, k: i32, sum: i32, temp: &mut Vec<i32>) {
        if sum == 0 && temp.len() == k as usize {
            result.push(temp.clone());
        } else if sum > 0 {
            let mut end = 9;
            while end > sum {
                end -= 1;
            }

            for i in start..=end {
                temp.push(i);
                Self::helper(result, i + 1, k, sum - i, temp);
                temp.pop();
            }
        }
    }

    pub fn combination_sum3(k: i32, n: i32) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = Vec::new();
        let mut temp: Vec<i32> = Vec::new();
        Self::helper(&mut result, 1, k, n, &mut temp);
        result
    }
}
