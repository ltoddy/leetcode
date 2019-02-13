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
    fn inorder_traversal(
        root: &Option<Rc<RefCell<TreeNode>>>,
        left_bound: i64,
        right_bound: i64,
    ) -> bool {
        match root {
            Some(root) => {
                let TreeNode { val, left, right } = &*root.borrow();
                let val = *val as i64;
                if val <= left_bound || val >= right_bound {
                    return false;
                }
                Self::inorder_traversal(left, left_bound, val)
                    && Self::inorder_traversal(right, val, right_bound)
            }
            None => true,
        }
    }

    #[inline]
    pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::inorder_traversal(&root, std::i64::MIN, std::i64::MAX)
    }
}
