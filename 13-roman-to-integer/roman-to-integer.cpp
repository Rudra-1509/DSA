class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mpp={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int ans=0,n=s.size();
        for(int i=0;i<n-1;i++){
            int cur=mpp[s[i]];
            if(cur<mpp[s[i+1]])    ans-=cur;
            else    ans+=cur;
        }
        ans+=mpp[s[n-1]];
        return ans;
    }
};