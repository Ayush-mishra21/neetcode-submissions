/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        Node *temp = head, *dummy = new Node(0), *temp1;
        temp1 = dummy;
        unordered_map<Node*, Node*> mpold, mprandom;
        while (temp != NULL) {
            mpold[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL) {
            if (temp->random)
                mprandom[temp] = mpold[temp->random];
            else
                mprandom[temp] = NULL;
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL) {
            temp1->next = mpold[temp];
            temp1->next->random = mprandom[temp];
            temp1 = mpold[temp];
            temp = temp->next;
        }
        return dummy->next;
    }
};
