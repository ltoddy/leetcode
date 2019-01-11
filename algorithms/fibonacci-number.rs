impl Solution {
    pub fn fib(n: i32) -> i32 {
        if n == 0 {
            return 0;
        } else if n == 1 {
            return 1;
        } else {
            return Solution::fib(n - 1) + Solution::fib(n - 2);
        }
    }
}
