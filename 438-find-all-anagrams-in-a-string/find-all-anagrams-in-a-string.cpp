class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mpp,window;
        vector<int> res;
        int k=p.size();
        for(char& ch:p)     mpp[ch]++;
        for(int i=0;i<s.size();i++){
            window[s[i]]++;
            if(i>=k-1){
                if(window==mpp) res.push_back(i-k+1);
                char ch=s[i-k+1];
                if(--window[ch]==0) window.erase(ch);
            }
        }
        return res;
    }
};