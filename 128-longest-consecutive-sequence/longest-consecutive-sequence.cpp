class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans=0;
        for(int x:nums)     s.insert(x);
        for(auto it:s){
            if(! s.count(it-1)){
                int cur=it,streak=0;
                while(s.count(cur)){
                    streak++;cur++;
                }
                ans=max(ans,streak);
            }
        }
        return ans;
    }
};