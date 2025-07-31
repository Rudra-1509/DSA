class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> mpp;
public:

    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key)==mpp.end())    return "";
        auto& arr=mpp[key];
        int left=0,right=arr.size()-1;
        string ans="";
        while(left<=right){
            int mid=left+(right-left)/2;
            if(timestamp>=arr[mid].first){
                ans=arr[mid].second;
                left=mid+1;
            }
            else   right=mid-1;  
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */