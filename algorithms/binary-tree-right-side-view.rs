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
use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;

impl Solution {
    fn level_order_traversal(root: Rc<RefCell<TreeNode>>) -> Vec<i32> {
        let mut result = Vec::new();
        let mut queue = VecDeque::new();
        queue.push_back(root);
        while !queue.is_empty() {
            let length = queue.len();
            for i in 0..length {
                let node = queue.pop_front().unwrap();
                let node = node.borrow();
                let TreeNode {
                    val, left, right, ..
                } = &*node;

                if i == length - 1 {
                    result.push(*val);
                }

                if let Some(left) = left {
                    queue.push_back(left.clone());
                }
                if let Some(right) = right {
                    queue.push_back(right.clone());
                }
            }
        }
        result
    }

    pub fn right_side_view(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        if let Some(root) = root {
            return Self::level_order_traversal(root);
        }
        Vec::new()
    }
}
