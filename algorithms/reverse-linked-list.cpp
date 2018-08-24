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
public:
    ListNode* reverseList(ListNode* head)
    {
        vector<int> data;
        ListNode* tmp = head;
        while (tmp != nullptr) {
            data.push_back(tmp->val);
            tmp = tmp->next;
        }

        ListNode* res = nullptr;
        ListNode* q = nullptr;
        for (int i = data.size() - 1; i >= 0; i--) {
            ListNode* p = new ListNode(data[i]);
            if (res == nullptr) res = q = p;
            else q->next = p;
            q = p;
        }
        return res;
    }
};
