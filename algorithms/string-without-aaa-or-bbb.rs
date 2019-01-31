impl Solution {
    pub fn str_without3a3b(a: i32, b: i32) -> String {
        let length = (a + b) as usize;
        let mut result = String::with_capacity(length);

        let ((mut a, chara), (mut b, charb)) = if a > b {
            ((a, 'a'), (b, 'b'))
        } else {
            ((b, 'b'), (a, 'a'))
        };

        while a > 0 || b > 0 {
            if a > 0 {
                result.push(chara);
                a -= 1;
            }
            if a > b {
                result.push(chara);
                a -= 1;
            }
            if b > 0 {
                result.push(charb);
                b -= 1;
            }
        }

        result
    }
}
