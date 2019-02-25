use std::collections::HashMap;
use std::iter::repeat;

impl Solution {
    pub fn frequency_sort(s: String) -> String {
        let mut counter: HashMap<char, usize> = HashMap::with_capacity(s.len());
        for c in s.chars() {
            counter.insert(c, *counter.get(&c).unwrap_or(&0) + 1);
        }
        let mut vec = counter.iter().collect::<Vec<(&char, &usize)>>();
        vec.sort_by_key(|tuple| tuple.1);
        vec.reverse();
        vec.iter()
            .flat_map(|tuple| repeat(tuple.0).zip(0..*tuple.1).map(|tuple| tuple.0))
            .collect::<String>()
    }
}
