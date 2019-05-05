impl Solution {
    pub fn prefixes_div_by5(a: Vec<i32>) -> Vec<bool> {
        let mut result: Vec<bool> = Vec::with_capacity(a.len());
        let mut remainder = 0;

        for i in 0..a.len() {
            remainder = (remainder << 1) % 5 + (if a[i] == 1 { 1 } else { 0 });
            result.push(remainder % 5 == 0);
        }

        result
    }
}
