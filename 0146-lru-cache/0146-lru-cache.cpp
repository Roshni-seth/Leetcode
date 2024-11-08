class LRUCache {
public:
    class Node {
        public:
            int key;
        int val;
        Node *next, *prev;
        Node(int new_key,int new_val) {
            key=new_key;
            val=new_val;
        }
    };
    void deletionNode(Node* node) {
        Node *prevNode=node->prev;
        Node *afterNode=node->next;
        prevNode->next=afterNode;
        afterNode->prev=prevNode;
    }
    void insertAfterHead(Node* node) {
        Node *currAfterHead=head->next;
        node->next=currAfterHead;
        node->prev=head;
        head->next=node;
        currAfterHead->prev=node;
    }
    unordered_map<int,Node*> mpp;
    int cap;
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    LRUCache(int capacity) {
        cap=capacity;
        // mpp.clear();
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        auto it=mpp.find(key);
        if(it==mpp.end()) {
            return -1;
        }
        Node *node=mpp[key];
        deletionNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        auto it=mpp.find(key);
        if(it!=mpp.end()) {
            Node *node=mpp[key];
            node->val=value;
            deletionNode(node);
            insertAfterHead(node);
        }
        else {
            if(mpp.size()==cap) {
                Node *node=tail->prev;
                mpp.erase(node->key);
                deletionNode(node);
            }
            Node *node=new Node(key,value);
            mpp[key]=node;
            insertAfterHead(node);
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */