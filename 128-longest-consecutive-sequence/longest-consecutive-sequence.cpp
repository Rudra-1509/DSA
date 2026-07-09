class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans=0;
        for(int x:nums)     s.insert(x);
        for(int x:s){
            if(!s.count(x-1)){
                int cur=x,streak=0;
                while(s.count(cur)){
                    cur++;streak++;
                }
                ans=max(ans,streak);
            }
        }
        return ans;
    }
};