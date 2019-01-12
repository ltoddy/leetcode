use std::collections::HashSet;

impl Solution {
    pub fn powerful_integers(x: i32, y: i32, bound: i32) -> Vec<i32> {
        let mut x_powers = Vec::with_capacity(bound as usize);
        for i in 0..bound {
            let power = f64::from(x).powi(i) as i32;
            if power > bound {
                break;
            }
            x_powers.push(f64::from(x).powi(i));
        }

        let mut y_powers = Vec::with_capacity(bound as usize);
        for i in 0..bound {
            let power = f64::from(y).powi(i) as i32;
            if power > bound {
                break;
            }
            y_powers.push(f64::from(y).powi(i));
        }

        let mut set = HashSet::new();
        for x in &x_powers {
            for y in &y_powers {
                if ((x + y) as i32) <= bound {
                    set.insert((x + y) as i32);
                } else {
                    break;
                }
            }
        }
        set.into_iter().collect()
    }
}
