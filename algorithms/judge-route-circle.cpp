class Solution
{
public:
    bool judgeCircle(string moves)
    {
        pair<int, int> origin = {0, 0}; // (0, 0)
        pair<int, int> coordinate = {0, 0}; // (x, y)
        for (char move: moves)
            switch (move) {
                case 'R':
                    coordinate.first += 1;
                    break;
                case 'L':
                    coordinate.first -= 1;
                    break;
                case 'U':
                    coordinate.second += 1;
                    break;
                case 'D':
                    coordinate.second -= 1;
                    break;
            }

        return coordinate == origin;
    }
};
