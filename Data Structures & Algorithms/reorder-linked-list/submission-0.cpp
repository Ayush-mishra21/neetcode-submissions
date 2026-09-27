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

        ListNode *temp = head;
        ListNode *prev = NULL;
        ListNode *nextnode;

        while (temp != NULL) {

            nextnode = temp->next;
            temp->next = prev;

            prev = temp;
            temp = nextnode;
        }

        return prev;
    }


    void reorderList(ListNode* head) {

        // -------------------------------
        // Step 1: Find middle
        // -------------------------------

        if (head == NULL || head->next == NULL)
            return;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {

            fast = fast->next->next;
            slow = slow->next;
        }


        // -------------------------------
        // Step 2: Reverse second half
        // -------------------------------

        ListNode* temp2 = reverseList(slow->next);

        // Break first half and second half
        slow->next = NULL;


        // -------------------------------
        // Step 3: First half
        // -------------------------------

        ListNode* temp1 = head;

        ListNode* dummy = NULL;
        ListNode* temp = NULL;


        // -------------------------------
        // Step 4: Merge alternatively
        // -------------------------------

        while (temp1 != NULL && temp2 != NULL) {

            // VERY IMPORTANT:
            // Save next nodes before changing links

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


            // Move to next nodes
            temp1 = next1;
            temp2 = next2;
        }


        // -------------------------------
        // Step 5: Remaining temp1
        // -------------------------------

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


        // -------------------------------
        // Step 6: Remaining temp2
        // -------------------------------

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


        // -------------------------------
        // Step 7: End list
        // -------------------------------

        if (temp != NULL)
            temp->next = NULL;
    }
};