class Solution {
public:
    map<Node*, Node*> mp;
    Node* head = NULL;

    void traverse(Node* node) {
        if (node == NULL) return;

        if (mp.find(node) != mp.end()) {
            return;
        }

        Node* newnode = new Node(node->val);

        mp[node] = newnode;

        if (head == NULL) {
            head = newnode;
        }

        for (Node* A : node->neighbors) {
            traverse(A);
            mp[node]->neighbors.push_back(mp[A]);
        }
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;

        traverse(node);

        return head;
    }
};