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

        this->data.push_back(root->val);
        for (auto* child: root->children) {
            this->traversal(child);
        }
    }

public:
    vector<int> preorder(Node* root)
    {
        this->traversal(root);
        return this->data;
    }
};
