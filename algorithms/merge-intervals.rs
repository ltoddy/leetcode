// Definition for an interval.
// #[derive(Debug, PartialEq, Eq)]
// pub struct Interval {
//   pub start: i32,
//   pub end: i32,
// }
//
// impl Interval {
//   #[inline]
//   pub fn new(start: i32, end: i32) -> Self {
//     Interval {
//       start,
//       end
//     }
//   }
// }
impl Solution {
    pub fn merge(intervals: Vec<Interval>) -> Vec<Interval> {
        if intervals.is_empty() {
            return intervals;
        }

        let mut intervals = intervals;
        intervals.sort_by(|prev, cur| {
            if (prev.start < cur.start) || (prev.start == cur.start && prev.end < cur.end) {
                std::cmp::Ordering::Less
            } else {
                std::cmp::Ordering::Greater
            }
        });

        let mut start = intervals[0].start;
        let mut end = intervals[0].end;
        let mut result: Vec<Interval> = Vec::with_capacity(intervals.len());
        for interval in intervals.iter().skip(1) {
            if end >= interval.start {
                if end < interval.end {
                    end = interval.end;
                }
            } else {
                result.push(Interval::new(start, end));
                start = interval.start;
                end = interval.end;
            }
        }
        result.push(Interval::new(start, end));
        result
    }
}
