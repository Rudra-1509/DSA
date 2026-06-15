class Solution {
public:
    // string longestPalindrome(string s) {
    //     if(s.empty())   return "";
    //     int start=0,maxlen=INT_MIN;
    //     for(int i=0;i<s.size();i++){
    //         expandAroundCenter(s,i,i,start,maxlen);
    //         expandAroundCenter(s,i,i+1,start,maxlen);
    //     }
    //     return s.substr(start,maxlen);
    // }
    // void expandAroundCenter(string& s,int left,int right,int& start,int& maxlen){
    //     while(left>=0 && right<s.size() && s[left]==s[right]){
    //         if(maxlen<right-left+1){
    //             maxlen=right-left+1;
    //             start=left;
    //         }
    //         left--;
    //         right++;
    //     }
    //}

    string longestPalindrome(string s) {
        int n=s.size(),start=0,maxlen=1;
        vector<vector<bool>> isPal(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)    isPal[i][i]=true;
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]==s[j] &&(len<=3 || isPal[i+1][j-1])){
                    isPal[i][j]=true;
                    if(len>maxlen){
                        maxlen=len;
                        start=i;
                    }
                }
            }
        }

        return s.substr(start,maxlen);
    }
};