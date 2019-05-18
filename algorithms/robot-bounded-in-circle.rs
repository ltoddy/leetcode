impl Solution {
    const ORIGIN: (isize, isize) = (0, 0);

    pub fn is_robot_bounded(instructions: String) -> bool {
        let mut current = (0, 0);
        let next = vec![(0, 1), (1, 0), (0, -1), (-1, 0)];
        let mut direction = 0;

        for _ in 0..4 {
            for instruction in instructions.chars() {
                if instruction == 'L' {
                    direction = (direction + 3) % 4;
                } else if instruction == 'R' {
                    direction = (direction + 1) % 4;
                } else {
                    current.0 += next[direction].0;
                    current.1 += next[direction].1;
                }
            }
        }

        current == Solution::ORIGIN
    }
}
