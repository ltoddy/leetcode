impl Solution {
    pub fn can_three_parts_equal_sum(a: Vec<i32>) -> bool {
        let sum = a.iter().sum::<i32>();
        if sum % 3 != 0 {
            return false;
        }

        let average = sum / 3;
        let (mut i, mut j) = (0, a.len() - 1);
        let (mut lefts, mut rights) = (0, 0);

        while i < j {
            if lefts != average {
                lefts += a[i];
                i += 1;
            }

            if rights != average {
                rights += a[j];
                j -= 1;
            }

            if lefts == average && rights == average {
                return true;
            }
        }

        false
    }
}
