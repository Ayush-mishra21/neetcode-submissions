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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int N = 0;
        ListNode *temp = head, *prev = NULL;
        while (temp != nullptr) {
            N++;
            temp = temp->next;
        }
        temp = head;
        N -= n;
        while (N >= 1) {
            prev = temp;
            temp = temp->next;
            N--;
        }
        if (prev) 
            prev->next = temp->next;
        else{
            if(head && head->next){
                return head->next;
            }
            return NULL;
        }
        return head;
    }
};
