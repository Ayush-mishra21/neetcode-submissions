/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pqmin;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) pqmin.push(lists[i]);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while (!pqmin.empty()) {
            ListNode* node = pqmin.top();
            pqmin.pop();
            temp->next = node;
            temp = node;
            if (node->next) {
                pqmin.push(node->next);
            }
            node->next = NULL;
        }
        return dummy->next;
    }
};
