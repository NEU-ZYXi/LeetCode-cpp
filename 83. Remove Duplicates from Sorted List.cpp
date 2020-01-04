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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = head;
        while (p) {
            while (p && p->next && p->val == p->next->val) {
                p->next = p->next->next;
            }
            p = p->next;
        }
        return dummy.next;
    }
};
