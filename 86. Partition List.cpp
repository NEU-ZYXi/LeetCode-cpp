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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0), *p1 = &dummy1;
        ListNode dummy2(0), *p2 = &dummy2;
        ListNode* cur = head;
        while (cur) {
            if (cur->val < x) {
                p1->next = cur;
                p1 = p1->next;
            } else {
                p2->next = cur;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        p1->next = dummy2.next;
        p2->next = NULL;
        return dummy1.next;
    }
};
