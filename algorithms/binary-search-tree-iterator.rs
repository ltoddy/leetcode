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

struct BSTIterator {
    stack: Vec<Rc<RefCell<TreeNode>>>,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl BSTIterator {
    fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
        let mut stack = Vec::new();

        let mut cur = root;
        while cur.is_some() {
            let node = cur.clone().unwrap();
            stack.push(node.clone());
            cur = cur.clone().unwrap().borrow().left.clone();
        }

        BSTIterator { stack }
    }

    /** @return the next smallest number */
    fn next(&mut self) -> i32 {
        let smallest = self.stack.pop().unwrap();
        let mut temp = smallest.clone().borrow().right.clone();
        while temp.is_some() {
            self.stack.push(temp.clone().unwrap());
            temp = temp.clone().unwrap().borrow().left.clone();
        }
        smallest.clone().borrow().val
    }

    /** @return whether we have a next smallest number */
    fn has_next(&self) -> bool {
        !self.stack.is_empty()
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * let obj = BSTIterator::new(root);
 * let ret_1: i32 = obj.next();
 * let ret_2: bool = obj.has_next();
 */
