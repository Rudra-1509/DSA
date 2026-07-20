class StockPrice {
private:
    unordered_map<int,int> mpp;
    pair<int,int> latest;

    struct maxCmp{
        bool operator()(pair<int,int>& a,pair<int,int>& b){
            return a.second<b.second;
        }
    };

    struct minCmp{
        bool operator()(pair<int,int>& a,pair<int,int>& b){
            return a.second>b.second;
        }
    };

    priority_queue<pair<int,int>,vector<pair<int,int>>,maxCmp> maxipq;
    priority_queue<pair<int,int>,vector<pair<int,int>>,minCmp> minipq;
public:
    StockPrice() {
        latest={-1,-1};
    }
    
    void update(int timestamp, int price) {
        mpp[timestamp]=price;
        if(timestamp>=latest.first){
            latest={timestamp,price};
        }
        maxipq.push({timestamp,price});
        minipq.push({timestamp,price});
    }
    
    int current() {
        return latest.second;
    }
    
    int maximum() {
        while(!maxipq.empty()){
            auto& [timestamp,price]=maxipq.top();
            if(price==mpp[timestamp])   return price;
            else    maxipq.pop();
        }
        return -1;
    }
    
    int minimum() {
        while(!minipq.empty()){
            auto& [timestamp,price]=minipq.top();
            if(price==mpp[timestamp])   return price;
            else    minipq.pop();
        }
        return -1;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */