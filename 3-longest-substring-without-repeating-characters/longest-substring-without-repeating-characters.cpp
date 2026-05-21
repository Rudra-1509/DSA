class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int> mpp;
       int len=0,left=0;
       for(int right=0;right<s.size();right++){
        char ch=s[right];
        mpp[ch]++;
        while(mpp[ch]>1)    mpp[s[left++]]--;
        len=max(len,right-left+1);
       }
       return len;
    }
};