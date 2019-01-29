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
    pub fn all_possible_fbt(n: i32) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        let mut result: Vec<Option<Rc<RefCell<TreeNode>>>> = Vec::new();

        if n == 1 {
            result.push(Some(Rc::new(RefCell::new(TreeNode::new(0)))));
            return result;
        }
        if n % 2 == 0 {
            return result;
        }
        let mut i = 1;
        while i < n {
            let left_tree = Self::all_possible_fbt(i);
            let right_tree = Self::all_possible_fbt(n - i - 1);

            for left_node in &left_tree {
                for right_node in &right_tree {
                    let mut node = TreeNode::new(0);
                    node.left = left_node.clone();
                    node.right = right_node.clone();
                    result.push(Some(Rc::new(RefCell::new(node))));
                }
            }

            i += 2;
        }

        result
    }
}
