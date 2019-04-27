impl Solution {
    pub fn remove_outer_parentheses(s: String) -> String {
        let mut stack = Vec::new();
        let mut index: usize = 0;
        let mut buffer = String::new();

        for (i, c) in s.chars().enumerate() {
            if c == '(' {
                stack.push(c);
            } else {
                stack.pop();
            }

            if stack.is_empty() {
                buffer.push_str(&s[(index + 1)..i]);
                index = i + 1;
            }
        }

        buffer
    }
}
