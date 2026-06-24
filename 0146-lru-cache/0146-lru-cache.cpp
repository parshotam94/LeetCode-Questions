class LRUCache {
public:
    class Node{
        public:
        int key, value;
        Node *prev, *next;
        Node(int key, int value){
            this->key=key;
            this->value=value;
        }
    };
    Node* head= new Node(-1, -1);
    Node* tail=new Node(-1, -1);
    int cap;
    unordered_map<int, Node*>mpp;
    LRUCache(int capacity) {    
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void insertAfterHead(Node *node){
        Node *temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
    }
    void deleteNode(Node *node){
        Node *prevNode=node->prev;
        Node *afterNode=node->next;
        prevNode->next=afterNode;
        afterNode->prev=prevNode;
    }

    
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node *node=mpp[key];
        int res=node->value;
        mpp.erase(key);
        deleteNode(node);
        insertAfterHead(node);
        mpp[key]=head->next;
        return res;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node *node=mpp[key];
            mpp.erase(key);
            deleteNode(node);
        }
        if(mpp.size()==cap){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        insertAfterHead(new Node(key, value));
        mpp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */