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

        while (temp != NULL) {

            nextnode = temp->next;
            temp->next = prev;

            prev = temp;
            temp = nextnode;
        }

        return head = prev;
    }


    void reorderList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return;


        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {

            fast = fast->next->next;
            slow = slow->next;
        }


        // Reverse second half
        ListNode* temp2 = reverseList(slow->next);

        // First half
        ListNode* temp1 = head;

        // Separate both halves
        slow->next = NULL;


        ListNode* dummy = NULL;
        ListNode* temp;


        // Merge temp1 and temp2
        while (temp1 != NULL && temp2 != NULL) {

            // Save original next nodes
            ListNode* next1 = temp1->next;
            ListNode* next2 = temp2->next;


            if (dummy == NULL) {

                dummy = temp1;
                temp = dummy;

                temp->next = temp2;
                temp = temp2;
            }
            else {

                temp->next = temp1;
                temp = temp1;

                temp->next = temp2;
                temp = temp2;
            }


            // Move forward
            temp1 = next1;
            temp2 = next2;
        }


        // Remaining temp1
        while (temp1 != NULL) {

            ListNode* next1 = temp1->next;

            if (dummy == NULL) {

                dummy = temp1;
                temp = dummy;
            }
            else {

                temp->next = temp1;
                temp = temp1;
            }

            temp1 = next1;
        }


        // Remaining temp2
        while (temp2 != NULL) {

            ListNode* next2 = temp2->next;

            if (dummy == NULL) {

                dummy = temp2;
                temp = dummy;
            }
            else {

                temp->next = temp2;
                temp = temp2;
            }

            temp2 = next2;
        }


        // Your dummy is the new beginning
        // head = dummy;

        // Make sure last node points to NULL
        if (temp != NULL)
            temp->next = NULL;
    }
};