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

impl Solution {
    fn dfs(root: Option<Rc<RefCell<TreeNode>>>, mut acc: i32) -> i32 {
        if root.is_none() {
            0
        } else {
            acc = acc * 10 + root.clone().unwrap().borrow().val;
            let left = root.clone().unwrap().borrow().left.clone();
            let right = root.clone().unwrap().borrow().right.clone();

            if left.is_none() && right.is_none() {
                acc
            } else {
                Self::dfs(left, acc) + Self::dfs(right, acc)
            }
        }
    }

    pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::dfs(root, 0)
    }
}
