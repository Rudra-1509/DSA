class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp,window;
        for(char ch:t)  mpp[ch]++;
        int left=0,st_index=0,len=INT_MAX,checklist=0;
        for(int right=0;right<s.size();right++){
            window[s[right]]++;
            if(mpp.count(s[right]) && mpp[s[right]]==window[s[right]])
                checklist++;
            while(checklist==mpp.size()){
                if(len>right-left+1){
                    len=right-left+1;
                    st_index=left;
                }
                char c=s[left];
                window[c]--;
                left++;
                if(mpp.count(c) && mpp[c]>window[c])
                    checklist--;
            }
        }
        return len==INT_MAX? "" : s.substr(st_index,len);
    }
};