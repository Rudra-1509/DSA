class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ans=0,prevlen=-1,maxi=0;
        for(int i=0;i<s.size();){
            int j=i;
            while(j<s.size() && s[j]==s[i]) j++;
            int curlen=j-i;
            if(s[i]=='1')
                ans+=curlen;
            else{
                if(prevlen!=-1)
                    maxi=max(maxi,prevlen+curlen);
                prevlen=curlen;
            }
            i=j;
        }
        return ans+maxi;
    }
};