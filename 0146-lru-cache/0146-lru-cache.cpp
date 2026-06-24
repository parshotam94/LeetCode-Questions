class LRUCache {
private:
    class Node{
        public:
        int key, value;
        Node *prev, *next;
        Node(int key, int value){
            this->key=key;
            this->value=value;
            prev=nullptr;
            next=nullptr;
        }
    };
    Node *head;
    Node *tail;
    unordered_map<int, Node*>mpp;
    int capacity;
    void deleteNode(Node *node){
        Node *prevNode=node->prev;
        Node *nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    void addNode(Node* node){
        Node *temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
    }
    
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1, -1);
        tail=new Node(-1, -1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node *temp=mpp[key];
        deleteNode(temp);
        addNode(temp);
        return temp->value;
    }
    
    void put(int key, int value) {
        //if key is already present;
        if(mpp.find(key)!=mpp.end()){
            Node *temp=mpp[key];
            deleteNode(temp);
            mpp.erase(key);
            delete temp;
        }
        //if capacity full
        if(mpp.size()==capacity){
            Node *temp=tail->prev;
            deleteNode(temp);
            mpp.erase(temp->key);
            delete temp;
        }
        Node *newNode=new Node(key, value);
        mpp[key]=newNode;
        addNode(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */