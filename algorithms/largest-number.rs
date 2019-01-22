use std::cmp::Ordering::{Less, Greater, Equal};

impl Solution {
    pub fn largest_number(nums: Vec<i32>) -> String {
        let mut nums = nums
            .iter()
            .map(|num| num.to_string())
            .collect::<Vec<String>>();

        nums.sort_by(|prev, cur| {
            let a = format!("{}{}", prev, cur);
            let b = format!("{}{}", cur, prev);
            if a > b {
                Less
            } else if a < b {
                Greater
            } else {
                Equal
            }
        });
        if nums[0] == "0" { String::from("0") } else { nums.join("") }
    }
}
