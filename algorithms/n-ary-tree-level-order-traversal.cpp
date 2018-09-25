/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution
{
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        if (root == nullptr) return {};

        vector<vector<int>> res;
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            vector<int> tmp;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                tmp.push_back(node->val);
                for (auto* child : node->children) {
                    que.push(child);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};
