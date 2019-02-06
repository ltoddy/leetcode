impl Solution {
    pub fn eval_rpn(tokens: Vec<String>) -> i32 {
        let mut stack: Vec<i32> = Vec::with_capacity(tokens.len());

        for token in tokens {
            let token = token.as_str();
            match token {
                "+" => {
                    let num1 = stack.pop().unwrap();
                    let num2 = stack.pop().unwrap();
                    stack.push(num1 + num2);
                }
                "-" => {
                    let num2 = stack.pop().unwrap();
                    let num1 = stack.pop().unwrap();
                    stack.push(num1 - num2);
                }
                "*" => {
                    let num1 = stack.pop().unwrap();
                    let num2 = stack.pop().unwrap();
                    stack.push(num1 * num2);
                }
                "/" => {
                    let num2 = stack.pop().unwrap();
                    let num1 = stack.pop().unwrap();
                    stack.push(num1 / num2);
                }
                _ => {
                    stack.push(token.parse::<i32>().unwrap());
                }
            }
        }

        stack.pop().unwrap()
    }
}
