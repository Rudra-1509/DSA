class MedianFinder {
public:
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
    MedianFinder() {}
    
    void addNum(int num) {
        if(pq1.empty() || num<=pq1.top())    pq1.push(num);
        else    pq2.push(num);
        if(pq2.size()>pq1.size()){
            int ele=pq2.top();pq2.pop();
            pq1.push(ele);
        }
        if(pq1.size()>pq2.size()+1){
            int ele=pq1.top();pq1.pop();
            pq2.push(ele);
        }
    }
    
    double findMedian() {
        if(pq1.size()>pq2.size())   return (double)pq1.top();
        else            return (pq1.top()+pq2.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */