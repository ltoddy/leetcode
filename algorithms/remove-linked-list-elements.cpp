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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* fake = new ListNode(0);
        fake->next = head;

        ListNode* prev = fake;

        while (prev->next != nullptr) {
            if (prev->next->val == val) {
                prev->next = prev->next->next;
            } else {
                prev = prev->next;
            }
        }

        return fake->next;
    }
};
