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
    pub fn width_of_binary_tree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut max_width: i32 = 0;

        if root.is_some() {
            let mut queue = VecDeque::new();
            queue.push_back((root.clone(), 0));

            while !queue.is_empty() {
                let length = queue.len();

                max_width = max_width.max(queue.back().unwrap().1 - queue.front().unwrap().1 + 1);

                for _ in 0..length {
                    let (node, width) = queue.pop_front().unwrap();

                    if node.is_some() {
                        let node = node.unwrap();

                        let left = &node.borrow().left;
                        let right = &node.borrow().right;

                        if left.is_some() {
                            queue.push_back((left.clone(), 2 * width));
                        }
                        if right.is_some() {
                            queue.push_back((right.clone(), 2 * width + 1));
                        }
                    }
                }

                if max_width < (length as i32) {
                    max_width = length as i32;
                }
            }
        }

        max_width
    }
}
