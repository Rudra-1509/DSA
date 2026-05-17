class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mpp,window;
        for(char ch:s1)  mpp[ch]++;
        int k=s1.size();
        for(int i=0;i<s2.size();i++){
            window[s2[i]]++;
            if(i>=k-1){
                if(mpp==window) return true;
                window[s2[i-k+1]]--;
                if(window[s2[i-k+1]]==0)    window.erase(s2[i-k+1]);
            }
        }
        return false;
    }
};