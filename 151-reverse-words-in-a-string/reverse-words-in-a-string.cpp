class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=n-1;
        string ans="";
        while(i>=0){
            while(i>=0 && s[i]==' ')    i--;
            if(i<0) break;
            int j=i;
            while(j>=0 && s[j]!=' ')     j--;
            ans+=s.substr(j+1,i-j);
            ans+=' ';
            i=j-1;
        }
        if(!ans.empty())    ans.pop_back();
        return ans;
    }
};