use std::cmp::Ordering;

impl Solution {
    pub fn k_closest(points: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let mut points = points;
        points.sort_by(|cur_point, next_point| {
            let cur_distance = f64::sqrt(f64::from(cur_point[0]).powi(2) + f64::from(cur_point[1]).powi(2));
            let next_distance = f64::sqrt(f64::from(next_point[0]).powi(2) + f64::from(next_point[1]).powi(2));

            if cur_distance < next_distance {
                Ordering::Less
            } else if cur_distance > next_distance {
                Ordering::Greater
            } else {
                Ordering::Equal
            }
        });

        let k = k as usize;
        points[0..k].to_vec()
    }
}
