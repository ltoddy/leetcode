impl Solution {
    pub fn two_city_sched_cost(costs: Vec<Vec<i32>>) -> i32 {
        let mut costs = costs;
        let mut result = 0;
        costs.sort_by(|a, b| {
            let cmp = (a[0] - a[1]) - (b[0] - b[1]);
            if cmp < 0 {
                std::cmp::Ordering::Less
            } else if cmp > 0 {
                std::cmp::Ordering::Greater
            } else {
                std::cmp::Ordering::Equal
            }
        });

        for i in 0..costs.len() {
            result += costs[i][if i < costs.len() / 2 { 0 } else { 1 }];
        }

        result
    }
}
