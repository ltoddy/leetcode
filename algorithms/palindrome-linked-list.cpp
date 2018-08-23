/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
private:
    bool _isPalindrome(vector<int>& data)
    {
        for (int i = 0; i < data.size() / 2; i++) {
            if (data[i] != data[data.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }

public:
    bool isPalindrome(ListNode* head)
    {
        vector<int> data = {};
        for (ListNode* tmp = head; tmp != NULL; tmp = tmp->next) {
            data.push_back(tmp->val);
        }
        return this->_isPalindrome(data);
    }
};
