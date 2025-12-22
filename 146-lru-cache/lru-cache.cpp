class LRUCache {
private:
    struct ListNode{
        ListNode* prev;
        int key;
        int val;
        ListNode* next;
        ListNode(int k,int dat){
            prev=next=nullptr;
            key=k;
            val=dat;
        }
    };
public:
    unordered_map<int,ListNode*> mpp;
    ListNode* dhead;
    ListNode* dtail;
    int cap;
    void deleteLRU(){
        ListNode* LRU=dtail->prev;
        mpp.erase(LRU->key);
        LRU->prev->next=LRU->next;
        LRU->next->prev=LRU->prev;
        delete LRU;
    }

    void addtoFront(ListNode* req){
        if(req->prev && req->next){
            req->prev->next=req->next;
            req->next->prev=req->prev;
        }
        ListNode* nex=dhead->next;
        dhead->next=req;
        req->prev=dhead;
        req->next=nex;
        nex->prev=req;
    }
    LRUCache(int capacity) {
        cap = capacity;
        dhead = new ListNode(-1, -1);
        dtail = new ListNode(-1, -1);
        dhead->next = dtail;
        dtail->prev = dhead;
    }
    
    int get(int key) {
        if(mpp.count(key)){
            ListNode* req=mpp[key];
            addtoFront(req);
            return req->val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(mpp.count(key)){
            ListNode* req=mpp[key];
            req->val=value;
            addtoFront(req);
        }
        else{
            if(mpp.size()==cap) {
                deleteLRU();
            }
            ListNode* newNode=new ListNode(key,value);
            addtoFront(newNode);
            mpp[key]=newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */