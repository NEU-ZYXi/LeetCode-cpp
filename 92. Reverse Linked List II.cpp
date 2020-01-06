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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0), *p = &dummy;
        dummy.next = head;
        for (int i = 0; i < m - 1; ++i) {
            p = p->next;
        }
        ListNode *cur = p->next, *nxt = cur->next;
        for (int i = 0; i < n - m; ++i) {
            cur->next = nxt->next;
            nxt->next = p->next;
            p->next = nxt;
            nxt = cur->next;
        }
        return dummy.next;
    }
};
