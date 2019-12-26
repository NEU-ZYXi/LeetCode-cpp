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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        for (ListNode* p = head; p; p = p->next) {
            n++;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy, *cur = head;
        while (n >= k) {
            for (int i = 1; i < k; ++i) {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = p->next;
                p->next = tmp;
            }
            p = cur;
            cur = p->next;
            n -= k;
        }
        return dummy.next;
    }
};
