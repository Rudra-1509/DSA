class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size())   return "";
        unordered_map<char,int> mpp,window;
        for(char ch:t)  mpp[ch]++;
        int len=INT_MAX,start,checklist=0,left=0;
        for(int right=0;right<s.size();right++){
            char rc=s[right];
            window[rc]++;
            if(mpp.count(rc) && mpp[rc]==window[rc])    
                checklist++;
            while(checklist==mpp.size()){
                if(len>right-left+1){
                    len=right-left+1;
                    start=left;
                }
                char lc=s[left];
                window[lc]--;
                if(mpp.count(lc) && window[lc]<mpp[lc]) 
                    checklist--;
                left++;
            }
        }
        return len==(INT_MAX) ? "" :s.substr(start,len);
    }
};