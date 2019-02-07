use std::collections::binary_heap::BinaryHeap;

impl Solution {
    pub fn kth_smallest(matrix: Vec<Vec<i32>>, k: i32) -> i32 {
        let k = k as usize;
        let mut pque = BinaryHeap::with_capacity(k);

        for v in matrix {
            for e in v {
                if pque.len() < k {
                    pque.push(e);
                } else if *pque.peek().unwrap() > e {
                    pque.pop();
                    pque.push(e);
                }
            }
        }

        pque.pop().unwrap()
    }
}
