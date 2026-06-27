class RandomizedSet {
private:
    vector<int> arr;
    unordered_map<int,int> mpp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mpp.count(val))  return  false;
        arr.push_back(val);
        mpp[val]=arr.size()-1;  
        return true; 
    }
    
    bool remove(int val) {
        if(!mpp.count(val)) return false;
        int curIdx=mpp[val],lastIdx=arr.size()-1;
        arr[curIdx]=arr[lastIdx];
        mpp[arr[lastIdx]]=curIdx;
        mpp.erase(val);
        arr.pop_back();
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */