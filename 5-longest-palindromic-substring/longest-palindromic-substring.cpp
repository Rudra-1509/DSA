class Solution {
public:
    int expand(string& s,int l,int r){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        int maxlen=0,start=0;
        string ans;
        for(int i=0;i<s.size();i++){
            int len1=expand(s,i,i);
            int len2=expand(s,i,i+1);
            int maxi=max(len1,len2);
            if(maxi>maxlen){
                start=i-(maxi-1)/2;
                maxlen=maxi;
            }
        }
        ans=s.substr(start,maxlen);
        return ans;
    }
};