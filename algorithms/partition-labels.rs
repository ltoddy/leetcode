use std::collections::HashMap;

impl Solution {
    pub fn partition_labels(s: String) -> Vec<i32> {
        let s = s.as_bytes();
        let mut last_indexes = HashMap::with_capacity(26);
        for (index, ch) in s.iter().enumerate() {
            last_indexes.insert(ch, index);
        }

        let mut result: Vec<i32> = Vec::new();
        let mut first_index: i32 = 0;
        while first_index < s.len() as i32 {
            let mut current_index = first_index;
            let mut last_index = first_index;
            while current_index < s.len() as i32 && current_index <= last_index {
                let dynamic_last_index = last_indexes[&s[current_index as usize]] as i32;
                if dynamic_last_index > last_index {
                    last_index = dynamic_last_index
                }
                current_index += 1;
            }
            result.push(last_index - first_index + 1);
            first_index = last_index + 1;
        }
        result
    }
}
