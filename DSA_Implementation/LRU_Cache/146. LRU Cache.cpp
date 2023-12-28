//https://labuladong.gitbook.io/algo-en/ii.-data-structure/lru_algorithm

//All are (Inseart, Search, Delete) : O(1)

class LRUCache {
private:
    class Node {
       public:
            int key, val;
            Node *next, *prev;
            Node(int key, int val){
                this->key = key;
                this->val = val;
                this->next = NULL;
                this->prev = NULL;
            }
    };
public:
    unordered_map<int, Node*> mp;
    Node* head = new Node(0, 0);
    Node* tail = new Node(0, 0);
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if(mp.find(key)==mp.end()) return -1; //not found
        Node* currNode = mp[key];
        remove(currNode);
        insert(currNode);
        return currNode->val;
    }

    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* currNode = mp[key];
            remove(currNode);
        }
        if(mp.size()==capacity) remove(tail->prev);
        Node* currNode = new Node(key, value);
        insert(currNode);
    }

    void insert(Node* currNode){
        currNode->next = head->next;
        head->next->prev = currNode;
        head->next = currNode;
        currNode->prev = head;
        mp[currNode->key] = currNode;
    }
    void remove(Node* currNode){
        mp.erase(currNode->key);
        currNode->prev->next = currNode->next;
        currNode->next->prev = currNode->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
