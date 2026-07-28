class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> frq(26,0);
        for(char& ch:s)
            frq[ch-'a']++;
        string res="",spl="";
        for(int i=0;i<26;i++){
            res+=string(frq[i]/2,i+'a');
            if(frq[i] & 1)  spl=i+'a';
        }
        string temp=res;
        reverse(temp.begin(),temp.end());
        res=res+spl+temp;
        return res;
    }
};