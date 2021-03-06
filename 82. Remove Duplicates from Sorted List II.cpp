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
        ListNode *fast = head, *slow = &dummy;
        while (fast && fast->next) {
            while (fast && fast->next && fast->val == fast->next->val) {
                fast = fast->next;
            }
            if (slow->next == fast) {
                slow = slow->next;
            } else {
                slow->next = fast->next;
            }
            fast = fast->next;
        }
        return dummy.next;
    }
};
