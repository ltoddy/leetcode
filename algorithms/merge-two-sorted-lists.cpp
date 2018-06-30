class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        auto* head = new ListNode(0);
        auto* tmp = head;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                tmp->next = l1;
                l1 = l1->next;
            } else {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }

        while (l1 != nullptr) {
            tmp->next = l1;
            l1 = l1->next;
            tmp = tmp->next;
        }
        while (l2 != nullptr) {
            tmp->next = l2;
            l2 = l2->next;
            tmp = tmp->next;
        }
        return head->next;
    }
};

