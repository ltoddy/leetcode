impl Solution {
    pub fn bitwise_complement(n: i32) -> i32 {
        if n == 0 {
            return 1;
        }

        let (mut t, mut k) = (0, n);
        while k > 0 {
            k >>= 1;
            t += 1;
        }

        !n & ((1 << t) - 1)
    }
}
