class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<string,long long> mpp;
        for(auto& rect:rectangles){
            int div=gcd(rect[0],rect[1]);
            string key=to_string(rect[0]/div)+'/'+to_string(rect[1]/div);
            mpp[key]++;
        }
        long long ans=0;
        for(auto it:mpp){
            long long count=it.second;
            if(count>1) ans+=count*(count-1)/2;
        }
        return ans;
    }
};