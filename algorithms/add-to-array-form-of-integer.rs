impl Solution {
    pub fn add_to_array_form(a: Vec<i32>, k: i32) -> Vec<i32> {
        let mut a = a;
        let mut k = k;
        a.reverse();

        let mut b: Vec<i32> = Vec::new();
        while k > 0 {
            b.push(k % 10);
            k /= 10;
        }

        let max = a.len().max(b.len());
        let mut result = vec![0; max + 1];
        for i in 0..max {
            let sum = if i < a.len().min(b.len()) {
                a[i] + b[i] + result[i]
            } else if a.len() > b.len() {
                result[i] + a[i]
            } else {
                result[i] + b[i]
            };
            result[i] = sum % 10;
            result[i + 1] += sum / 10;
        }

        if result.last() == Some(&0) {
            result.pop();
        }
        result.reverse();
        result
    }
}
