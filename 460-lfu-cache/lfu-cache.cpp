class LFUCache {
private:
    struct ListNode{
        ListNode* prev;
        int key;
        int val;
        int freq;
        ListNode* next;
        ListNode(int k,int v,int f):key(k),val(v),freq(f),prev(nullptr),next(nullptr){}
    };
public:
    int cap,leastfrq;
    unordered_map<int,ListNode*> mpp;
    unordered_map<int,pair<ListNode*,ListNode*>> frqList;
    void newList(int freq){
        ListNode* head=new ListNode(-1,-1,-freq);
        ListNode* tail=new ListNode(-1,-1,-freq);
        head->next=tail;
        tail->prev=head;
        frqList[freq]={head,tail};
    }
    void deleteNode(ListNode* node){
        node->next->prev=node->prev;
        node->prev->next=node->next; 
    }
    bool emptyList(int frq){
        ListNode* head=frqList[frq].first;
        ListNode* tail=frqList[frq].second;
        return head->next==tail;
    }
    void updateFreq(ListNode* node){
        int freq=node->freq;
        deleteNode(node);
        if(freq==leastfrq && emptyList(freq)){
            leastfrq++;
        }
        node->freq++;
        addtoNextfreq(node,node->freq);
    }
    void addtoNextfreq(ListNode* node,int freq){
            if(!frqList.count(freq))    newList(freq);
            ListNode* head=frqList[freq].first;
            ListNode* nex=head->next;
            head->next=node;
            node->prev=head;
            node->next=nex;
            nex->prev=node;
    }
    LFUCache(int capacity) {
        cap=capacity;
        leastfrq=0;
    }
    
    int get(int key) {
        if(mpp.count(key)){
            ListNode* req=mpp[key];
            updateFreq(req);
            return req->val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(mpp.count(key)){
            ListNode* req=mpp[key];
            req->val=value;
            updateFreq(req);
        }
        else{
            if(mpp.size()==cap){
                ListNode* tail=frqList[leastfrq].second;
                ListNode* evict=tail->prev;
                mpp.erase(evict->key);
                deleteNode(evict);
                delete evict;
            }
            ListNode* newNode=new ListNode(key,value,1);
            addtoNextfreq(newNode,1);
            mpp[key] = newNode;
            leastfrq = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */