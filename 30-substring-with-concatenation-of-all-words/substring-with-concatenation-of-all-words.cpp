class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.empty() || s.empty()) return {};
        vector<int> res;
        unordered_map<string,int> mpp,window;
        int totalwords=words.size(),len=words[0].size(),count=0;
        for(string& word:words)
            mpp[word]++;
        for(int i=0;i<len;i++){
            int left=i;
            window.clear();
            count=0;
            for(int right=i;right+len<=s.size();right+=len){
                string word=s.substr(right,len);
                if(!mpp.count(word)){
                    window.clear();
                    count=0;
                    left=right+len;
                    continue;
                }
                window[word]++;
                count++;
                while(window[word]>mpp[word]){
                    string temp=s.substr(left,len);
                    window[temp]--;
                    left+=len;
                    count--;
                }
                if(totalwords==count){
                    res.push_back(left);
                    string temp=s.substr(left,len);
                    window[temp]--;
                    left+=len;
                    count--;
                }
            }
        }
        return res;   
    }
};