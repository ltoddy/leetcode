/*
// Definition for a Node.
class Node {
public:
    int val;
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
private:
    vector<int> data;

    void traversal(Node* root)
    {
        if (root == nullptr) return;

        for (auto* child : root->children) {
            this->traversal(child);
        }
        this->data.push_back(root->val);
    }

public:
    vector<int> postorder(Node* root)
    {
        this->traversal(root);
        return this->data;
    }
};
