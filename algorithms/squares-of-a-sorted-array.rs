impl Solution {
    #[inline]
    fn pow2(num: i32) -> i32 {
        num * num
    }

    pub fn sorted_squares(a: Vec<i32>) -> Vec<i32> {
        let mut a = a.iter().map(|num| Self::pow2(*num)).collect::<Vec<i32>>();
        a.sort();
        a
    }
}
