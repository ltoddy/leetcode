class Solution
{
public:
    double largestTriangleArea(vector<vector<int>>& points)
    {
        // 面积公式: area = 1/2 * [x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)]
        double area = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                for (int k = 0; k < points.size(); k++) {
                    double tmp = 1.0 / 2.0 * (points[i][0] * (points[j][1] - points[k][1]) +
                                              points[j][0] * (points[k][1] - points[i][1]) +
                                              points[k][0] * (points[i][1] - points[j][1]));
                    area = max(area, tmp);
                }
            }
        }
        return area;
    }
};
