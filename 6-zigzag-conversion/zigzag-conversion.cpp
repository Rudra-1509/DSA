class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=s.size()) return s;
        vector<string> arr(numRows,"");
        bool goDown=false;
        int arrIdx=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            arr[arrIdx]+=ch;
            if(arrIdx == 0 || arrIdx == numRows - 1)   goDown=!goDown;
            arrIdx+=goDown ? 1:-1;
        }
        string ans="";
        for(string& str:arr)
            ans+=str;
        return ans;
    }
};