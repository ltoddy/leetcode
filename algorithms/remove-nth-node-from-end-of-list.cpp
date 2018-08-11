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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* tmp = head;
        ListNode* res = head;

        for (int i = 0; i < n; i++) {
            tmp = tmp->next;
        }

        if (tmp == nullptr) return res->next;

        while (tmp->next != nullptr) {
            tmp = tmp->next;
            res = res->next;
        }

        res->next = res->next->next;
        return head;
    }
};
