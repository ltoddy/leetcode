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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {

        auto* head = new ListNode(-1);
        auto* tmp = head;
        int carry = 0; // 进位

        while (l1 != NULL || l2 != NULL) {
            int sum = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + carry;
            carry = sum / 10;
            tmp->next = new ListNode(sum % 10);
            tmp = tmp->next;
            l1 = l1 == NULL ? l1 : l1->next;
            l2 = l2 == NULL ? l2 : l2->next;
        }

        if (carry > 0) tmp->next = new ListNode(carry);

        return head->next;
    }
};
