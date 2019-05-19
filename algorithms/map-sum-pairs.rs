use std::collections::HashMap;

struct MapSum {
    map: HashMap<String, i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MapSum {
    /** Initialize your data structure here. */
    fn new() -> Self {
        MapSum {
            map: HashMap::new(),
        }
    }

    fn insert(&mut self, key: String, val: i32) {
        self.map.insert(key, val);
    }

    fn sum(&self, prefix: String) -> i32 {
        let prefix = prefix.as_str();

        self.map
            .iter()
            .filter_map(|(key, value)| {
                if key.starts_with(prefix) {
                    Some(value)
                } else {
                    None
                }
            })
            .sum()
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * let obj = MapSum::new();
 * obj.insert(key, val);
 * let ret_2: i32 = obj.sum(prefix);
 */
