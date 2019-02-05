impl Solution {
    pub fn num_rabbits(answers: Vec<i32>) -> i32 {
        if answers.is_empty() {
            return 0;
        }

        let mut result = 0;
        let mut bucket = [0; 1010];

        for i in 0..answers.len() {
            bucket[answers[i] as usize] += 1;
        }
        for (i, el) in bucket.iter().enumerate() {
            if el % (i + 1) != 0 {
                result += (el / (i + 1) + 1) * (i + 1);
            } else {
                result += el;
            }
        }

        result as i32
    }
}
