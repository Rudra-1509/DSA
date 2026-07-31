class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int,int> mpp;
        int mask=0,ans=0;
        mpp[0]=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a')        mask^=(1<<0);
            else if(s[i]=='e')   mask^=(1<<1);
            else if(s[i]=='i')   mask^=(1<<2);
            else if(s[i]=='o')   mask^=(1<<3);
            else if(s[i]=='u')   mask^=(1<<4);

            if(mpp.count(mask)) ans=max(ans,i-mpp[mask]);
            else    mpp[mask]=i;
        }
        return ans;
    }
};