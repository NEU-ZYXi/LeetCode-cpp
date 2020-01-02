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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) {
            return head;
        }
        ListNode dummy(0), *p = &dummy;
        p->next = head;
        ListNode *fast = p, *slow = p;
        int len = 0;
        while (fast->next) {
            fast = fast->next;
            len++;
        }
        for (int i = 0; i < len - k % len; ++i) {
            slow = slow->next;
        }
        fast->next = p->next;
        p->next = slow->next;
        slow->next = NULL;
        return dummy.next;
    }
};
