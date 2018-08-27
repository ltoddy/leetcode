class Solution:
    def isToeplitzMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        if not matrix:
            return False

        for row in range(len(matrix) - 1):
            if matrix[row][:len(matrix[row]) - 1] != matrix[row + 1][1:len(matrix[row])]:
                return False
        return True
