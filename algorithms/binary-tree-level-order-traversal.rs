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
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = Vec::new();

        if root.is_some() {
            let mut queue = VecDeque::new();
            queue.push_back(root.clone().unwrap());

            while !queue.is_empty() {
                let mut temp = Vec::new();
                let length = queue.len();

                for _ in 0..length {
                    let node = queue.pop_front().unwrap();
                    temp.push(node.borrow().val);
                    let left = &node.borrow().left;
                    let right = &node.borrow().right;

                    if left.is_some() {
                        queue.push_back(left.clone().unwrap());
                    }
                    if right.is_some() {
                        queue.push_back(right.clone().unwrap());
                    }
                }

                result.push(temp);
            }
        }
        result
    }
}
