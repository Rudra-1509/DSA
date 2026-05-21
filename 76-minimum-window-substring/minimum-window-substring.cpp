class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp,window;
        for(char ch:t)  mpp[ch]++;
        int left=0,checklist=0,len=INT_MAX,st_index=0;
        for(int right=0;right<s.size();right++){
            window[s[right]]++;
            if(mpp.count(s[right]) && mpp[s[right]]==window[s[right]])
                checklist++;
            while(checklist==mpp.size()){
                if(len>right-left+1){
                    len=right-left+1;
                    st_index=left;
                }
                window[s[left]]--;
                if(mpp.count(s[left]) && window[s[left]]<mpp[s[left]])
                    checklist--;
                left++;
            }
        }   
        return len==INT_MAX? "" :s.substr(st_index,len);

    }
};