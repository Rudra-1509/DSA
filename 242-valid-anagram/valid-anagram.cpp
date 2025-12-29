class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())  return false;
        unordered_map<char,int> mpp1;
        for(char ch: s) mpp1[ch]++;
        for(char ch: t){
            if(!mpp1.count(ch)) return false; 
            mpp1[ch]--;
            if(mpp1[ch]==0) mpp1.erase(ch);
        }
        return mpp1.empty();
    }
};