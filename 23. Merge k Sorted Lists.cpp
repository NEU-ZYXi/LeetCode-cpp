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
    struct compare {
        bool operator()(const ListNode* l1, const ListNode* l2) {
            return l1->val > l2->val;
        }    
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0), *p = &dummy;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (ListNode* list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        while (pq.size()) {
            p->next = pq.top();
            pq.pop();
            p = p->next;
            if (p->next) {
                pq.push(p->next);
            }
        }
        return dummy.next;
    }
};
