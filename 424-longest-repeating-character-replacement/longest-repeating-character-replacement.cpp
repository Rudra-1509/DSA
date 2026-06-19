class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,maxlen=0,maxfreq=0;
        unordered_map<char,int> mpp;
        for(int right=0;right<s.size();right++){
            mpp[s[right]]++;
            maxfreq=max(maxfreq,mpp[s[right]]);
            while(right-left+1-maxfreq>k){
                mpp[s[left++]]--;
                if(mpp[s[left]]==0) mpp.erase(s[left]);
            }
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};