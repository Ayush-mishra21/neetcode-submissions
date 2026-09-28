class LinkedList {
   public:
    int val;
    LinkedList *next, *prev;
    LinkedList(int data) {
        val = data;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
   public:
    LinkedList *head = NULL, *temp;
    unordered_map<int, LinkedList*> mp;
    int cap = 0;
    LRUCache(int capacity) { cap = capacity; }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            if (mp[key] == temp) {
                return temp->val;
            };
            if (mp[key]->prev) {
                mp[key]->prev->next = mp[key]->next;
                if (mp[key]->next) {
                    mp[key]->next->prev = mp[key]->prev;
                }
            } else {
                head = mp[key]->next;
                if (mp[key]->next) {
                    mp[key]->next->prev = NULL;
                }
            }
            temp->next = mp[key];
            mp[key]->prev = temp;
            temp = mp[key];
            mp[key]->next = NULL;
            return mp[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            if (cap == 0) {
                if (head->next) {
                    head->next->prev = NULL;
                }
                LinkedList* n = head;
                head = head->next;
                cap++;
                for (auto it = mp.begin(); it != mp.end(); it++) {
                    if (it->second == n) {
                        mp.erase(it);
                        break;
                    }
                }
                delete n;
            }
            LinkedList* node = new LinkedList(value);
            mp[key] = node;
            if (head == NULL) {
                head = mp[key];
                temp = head;
            } else {
                temp->next = mp[key];
                mp[key]->prev = temp;
                temp = mp[key];
            }
            this->cap -= 1;
        } else {
            mp[key]->val = value;  
            if(mp[key] == temp)return;
            if (mp[key]->prev) {
                mp[key]->prev->next = mp[key]->next;
                if (mp[key]->next) {
                    mp[key]->next->prev = mp[key]->prev;
                }
            } else {
                head = mp[key]->next;
                if (head) {
                    head->prev = NULL;
                }
            }
           // mp[key]->val = value;
            temp->next = mp[key];
            mp[key]->prev = temp;
            temp = mp[key];
            mp[key]->next = NULL;
        }
    }
};
