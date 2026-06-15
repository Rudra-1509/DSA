class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mpp,window;
        vector<int> res;
        for(char ch:p)  mpp[ch]++;
        int k=p.size();
        for(int i=0;i<s.size();i++){
            window[s[i]]++;
            if(i>=k-1){
                if(mpp==window)
                    res.push_back(i-k+1);
                window[s[i-k+1]]--;
                if(window[s[i-k+1]]==0) window.erase(s[i-k+1]);
            }
        }
        return res;
    }
};