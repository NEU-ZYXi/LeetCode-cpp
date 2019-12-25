/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        while (p->next && p->next->next) {
            ListNode *l1 = p->next, *l2 = p->next->next;
            l1->next = l2->next;
            l2->next = l1;
            p->next = l2;
            p = l1;
        }
        return dummy.next;
    }
};
