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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0), *prev = &dummy;
        int sum = 0;
        while (l1 || l2) {
            sum /= 10;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            prev->next = new ListNode(sum % 10);
            prev = prev->next;
        }
        if (sum >= 10) {
            prev->next = new ListNode(1);
        }
        return dummy.next;
    }
};
