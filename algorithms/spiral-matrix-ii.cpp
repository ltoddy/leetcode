class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n));
//        上、下、左、右边界
        int up = 0, down = n - 1, left = 0, right = n - 1;
        int num = 1;
        while (num <= n * n) {
//            从左向右
            for (int col = left; col <= right; col++)
                res[up][col] = num++;
            up++;
//            从上到下
            for (int row = up; row <= down; row++)
                res[row][right] = num++;
            right--;
//            从右向左
            for (int col = right; col >= left; col--)
                res[down][col] = num++;
            down--;
//            从下到上
            for (int row = down; row >= up; row--)
                res[row][left] = num++;
            left++;
        }
        return res;
    }
};
