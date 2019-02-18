impl Solution {
    pub fn score_of_parentheses(s: String) -> i32 {
        let mut stack = Vec::with_capacity(s.len());

        for c in s.chars() {
            if c == '(' {
                stack.push("(".to_string());
            } else if stack.last() == Some(&"(".to_string()) {
                stack.pop();
                stack.push("1".to_string());
            } else {
                let mut temp = 0;
                while stack.last() != Some(&"(".to_string()) {
                    temp += stack.last().unwrap().parse::<i32>().unwrap();
                    stack.pop();
                }
                if !stack.is_empty() {
                    stack.pop();
                }
                stack.push((temp * 2).to_string());
            }
        }

        let mut result = 0;
        while !stack.is_empty() {
            result += stack.pop().unwrap().parse::<i32>().unwrap();
        }
        result
    }
}
