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
    ListNode* reverseList(ListNode* head) {
        ListNode *temp = head, *prev = NULL, *nextnode;
        while(temp != NULL){
            nextnode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextnode;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head, *prev = NULL;
        int K = 1;
        while(temp != NULL){
            if(K % k == 0){
                if(prev == NULL){
                    ListNode* node = temp->next;
                    temp->next = NULL;
                    prev = head;
                    head = reverseList(head);
                    prev->next = node;
                    temp = node;
                }
                else{
                    ListNode* node = temp->next, *nodd = prev->next;
                    temp->next = NULL;
                    prev->next = reverseList(prev->next);
                    prev = nodd;
                    temp = node;
                    prev->next = temp;
                }
            }
            else{
                temp = temp->next;
            }
            K++;
        }
        return head;
    }
};
