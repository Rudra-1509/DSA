class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,res=0,maxfreq=0;
        unordered_map<char,int> mpp;
        for(int right=0;right<s.size();right++){
            mpp[s[right]]++;
            maxfreq=max(maxfreq,mpp[s[right]]);
            while(right-left+1 - maxfreq > k){
                mpp[s[left]]--;
                left++;
            }
            res=max(res,right-left+1);
        }
        return res;
    }
};