impl Solution {
    pub fn sum_even_after_queries(a: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut a = a;
        let mut result: Vec<i32> = Vec::with_capacity(queries.len());
        for query in queries {
            let val = query[0];
            let index = query[1] as usize;
            a[index] += val;
            result.push(a.iter().filter(|&&num| num & 1 == 0).sum());
        }
        result
    }
}
