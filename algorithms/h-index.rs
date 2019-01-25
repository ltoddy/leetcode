impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let mut citations = citations;
        citations.sort();
        citations.reverse();

        let mut h = 0;
        for citation in citations {
            if citation > h {
                h += 1;
            } else {
                break;
            }
        }

        h
    }
}
