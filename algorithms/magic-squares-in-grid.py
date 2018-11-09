from itertools import chain


class Solution:
    def is_magic_squares_inside(self, grid, row, col):
        s = set(chain.from_iterable(list(map(lambda x: x[col:col + 3], grid[row:row + 3]))))
        if s != {1, 2, 3, 4, 5, 6, 7, 8, 9}: return False

        sum1 = grid[row + 0][col + 0] + grid[row + 1][col + 0] + grid[row + 2][col + 0];
        sum2 = grid[row + 0][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1];
        sum3 = grid[row + 0][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2];

        sum4 = grid[row + 0][col + 0] + grid[row + 0][col + 1] + grid[row + 0][col + 2];
        sum5 = grid[row + 1][col + 0] + grid[row + 1][col + 1] + grid[row + 1][col + 2];
        sum6 = grid[row + 2][col + 0] + grid[row + 2][col + 1] + grid[row + 2][col + 2];

        sum7 = grid[row + 0][col + 0] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        sum8 = grid[row + 0][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col + 0];
        return sum1 == sum2 == sum3 == sum4 == sum5 == sum6 == sum7 == sum8

    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        res = 0
        for i in range(len(grid) - 2):
            for j in range(len(grid[i]) - 2):
                res = res + int(self.is_magic_squares_inside(grid, i, j))
        return res
