impl Solution {
    pub fn largest_sum_after_k_negations(a: Vec<i32>, k: i32) -> i32 {
        let mut result: i32 = a.iter().sum();
        let mut a: Vec<i32> = a;
        a.sort();

        for _ in 0..k {
            let mut min_index: usize = 0;
            for j in 0..a.len() {
                if a[j] < a[min_index] {
                    min_index = j;
                }
            }
            result -= 2 * a[min_index];
            a[min_index] = -a[min_index];
        }

        result
    }
}
