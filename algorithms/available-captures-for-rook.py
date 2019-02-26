class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'R':
                    row, col = i, j

        result = 0
        for i in range(row -1, -1, -1):
            if board[i][col] == 'B':
                break
            if board[i][col] == 'p':
                result += 1
                break

        for i in range(row + 1, 8):
            if board[i][col] == 'B':
                break
            if board[i][col] == 'p':
                result += 1
                break

        for i in range(col -1, -1, -1):
            if board[row][i] == 'B':
                break
            if board[row][i] == 'p':
                result += 1
                break

        for i in range(col + 1, 8):
            if board[row][i] == 'B':
                break
            if board[row][i] == 'p':
                result += 1
                break

        return result
