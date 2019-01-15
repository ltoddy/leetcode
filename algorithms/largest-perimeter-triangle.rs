use std::cmp::Ordering;

impl Solution {
    #[inline(always)]
    fn can(three: &[i32]) -> bool {
        three[0] + three[1] > three[2] && three[0] - three[1] < three[2]
    }

    pub fn largest_perimeter(a: Vec<i32>) -> i32 {
        let mut edges = a;
        edges.sort_by(|cur, next| {
            if cur > next {
                Ordering::Less
            } else if cur < next {
                Ordering::Greater
            } else {
                Ordering::Equal
            }
        });

        for three in edges.windows(3) {
            if Self::can(three) {
                return three.iter().sum();
            }
        }
        0
    }
}
