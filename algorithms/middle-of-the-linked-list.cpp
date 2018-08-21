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
    ListNode* middleNode(ListNode* head)
    {
        ListNode* faster = head, * slower = head;
        while (faster->next != NULL) {
            slower = slower->next;
            if (faster->next->next == NULL) break;
            faster = faster->next->next;
        }
        return slower;
    }
};
