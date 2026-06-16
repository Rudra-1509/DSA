struct Node{
    Node* prev;
    int key;
    int val;
    Node* next;
    Node(int x,int y){
        prev=nullptr;next=nullptr;key=x;val=y;
    }
};

class LRUCache {
private:
    Node* dummyhead;
    Node* dummytail;
    int cap,size;
    unordered_map<int,Node*> mpp;
    void addToFront(Node* ptr){
        ptr->prev=dummyhead;
        ptr->next=dummyhead->next;
        dummyhead->next=ptr;
        ptr->next->prev=ptr;
    }

    void deleteFromList(Node* ptr){
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
    }

    void deleteLRU(){
        Node* ptr=dummytail->prev;
        deleteFromList(ptr);
        mpp.erase(ptr->key);
        size--;
    }

public:
    LRUCache(int capacity) {
        cap=capacity;size=0;
        dummyhead=new Node(-1,-1);
        dummytail=new Node(-1,-1);
        dummyhead->next=dummytail;
        dummytail->prev=dummyhead;
    }
    
    int get(int key) {
        if(! mpp.count(key))  return -1;
        Node* ptr=mpp[key];
        deleteFromList(ptr);
        addToFront(ptr);
        return ptr->val;
    }
    
    void put(int key, int value) {
        if(mpp.count(key)){
            Node* ptr=mpp[key];
            ptr->val=value;
            deleteFromList(ptr);
            addToFront(ptr);
        }else{
            Node* ptr=new Node(key,value);
            mpp[key]=ptr;
            addToFront(ptr);
            size++;
            if(size>cap)
                deleteLRU();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */