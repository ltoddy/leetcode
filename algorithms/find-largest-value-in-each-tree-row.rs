// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::VecDeque;

impl Solution {
    pub fn largest_values(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut result = Vec::new();
        if let Some(root) = root {
            let mut queue = VecDeque::new();
            queue.push_back(root);
            while !queue.is_empty() {
                let length = queue.len();
                let mut temp = Vec::new();
                for _ in 0..length {
                    let node = queue.pop_front().unwrap();
                    let val = node.borrow().val;
                    let left = node.borrow().left.clone();
                    let right = node.borrow().right.clone();

                    temp.push(val);
                    if let Some(left) = left {
                        queue.push_back(left);
                    }
                    if let Some(right) = right {
                        queue.push_back(right);
                    }
                }
                let max = temp.iter().fold(i32::min_value(), |acc, num| acc.max(*num));
                result.push(max);
            }
        }
        result
    }
}
