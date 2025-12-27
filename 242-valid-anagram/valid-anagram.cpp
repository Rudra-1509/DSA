class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp1,mpp2;
        for(char ch: s) mpp1[ch]++;
        for(char ch: t) mpp2[ch]++;
        return mpp1==mpp2;
    }
};