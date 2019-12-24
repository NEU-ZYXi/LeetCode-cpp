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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *fast = &dummy, *slow = &dummy;
        while (fast->next) {
            if (n <= 0) {
                slow = slow->next;
            }
            fast = fast->next;
            n--;
        }
        if (slow->next) {
            slow->next = slow->next->next;
        }
        return dummy.next;
    }
};
