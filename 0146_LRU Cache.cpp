class LRUCache {
    struct Node{
        Node* prev;
        Node* next;
        int key;
        int val; 
        Node(int key, int val): prev(nullptr), next(nullptr), key(key), val(val){}
    };
    Node* head;
    Node* tail;
    int c;
    int length;
    unordered_map<int, Node*> dic;
    
    void hit(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void evict(){
        Node* toEvict = tail->prev;
        toEvict->prev->next = tail;
        tail->prev = toEvict->prev;
        dic.erase(toEvict->key);
        delete toEvict;
    }
public:
    LRUCache(int capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        c = capacity;
        length = 0;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (dic.find(key) == dic.end()) return -1;
        int val = dic[key]->val;
        hit(dic[key]);
        return val;
    }
    
    void put(int key, int value) {
        if (dic.find(key) != dic.end()){
            dic[key]->val = value;
            hit(dic[key]);
        } else {
            Node* node = new Node(key, value);
            dic[key] = node;
            node->prev = head;
            node->next = head->next;
            head->next->prev = node;
            head->next = node;
            length += 1;
            if (length > c){
                length--;
                evict();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
