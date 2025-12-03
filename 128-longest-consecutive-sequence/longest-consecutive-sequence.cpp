class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)   return 0;
        unordered_set s(nums.begin(),nums.end());
        int ans=INT_MIN;
        for(int x:s){
            if(!s.count(x-1)){
                int cur=x;
                int streak=1;
                while(s.count(cur+1)) streak++,cur++;
                ans=max(ans,streak);
            }
        }
        return ans;
    }
};