class Solution {
public:
    string getBin(char ch){
        int ascii=ch;
        string res="";
        while(ascii){
            int rem=ascii%2;
            ascii/=2;
            res+=rem+'0';
        }
        while(res.size()<8)
            res+='0';
        reverse(res.begin(),res.end());
        return res;
    }
    bool isPal(string s){
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r])  return false;
            l++;r--;
        }
        return true;
    }
    bool isPalindromic(string s) {
        string total="";
        for(char ch:s)
            total+=getBin(ch);
        return isPal(total);
    }
};