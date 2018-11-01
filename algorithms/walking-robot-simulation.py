class Solution:
    def robotSim(self, commands, obstacles):
        """
        :type commands: List[int]
        :type obstacles: List[List[int]]
        :rtype: int
        """
        next = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        x, y, direction, result = 0, 0, 0, 0
        obstacles = set((tuple(obstacle) for obstacle in obstacles))

        for command in commands:
            if command == -2:
                direction = (direction - 1) % 4
            elif command == -1:
                direction = (direction + 1) % 4
            else:
                for _ in range(command):
                    if (x + next[direction][0], y + next[direction][1]) not in obstacles:
                        x = x + next[direction][0]
                        y = y + next[direction][1]
                        result = max(result, x * x + y * y)

        return result
