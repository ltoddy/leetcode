/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution
{
private:
    Node* traversal(vector<vector<int>>& grid, int x, int y, int size)
    {
        if (size == 1) return new Node(grid[x][y] == 1 ? true : false, true, nullptr, nullptr, nullptr, nullptr);

        size /= 2;
        auto topLeft = this->traversal(grid, x, y, size);
        auto topRight = this->traversal(grid, x, y + size, size);
        auto bottomLeft = this->traversal(grid, x + size, y, size);
        auto bottomRight = this->traversal(grid, x + size, y + size, size);

        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && \
            topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val) {
            bool v = topLeft->val;
            delete topLeft, topRight, bottomLeft, bottomRight;
            return new Node(v, true, nullptr, nullptr, nullptr, nullptr);
        } else {
            return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
        }
    }

public:
    Node* construct(vector<vector<int>>& grid)
    {
        if (grid.empty()) return nullptr;

        return this->traversal(grid, 0, 0, grid.size());
    }
};
