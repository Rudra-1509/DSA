class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty())  return {};
        vector<int> res;
        int len=words[0].size(),n=s.size();
        unordered_map<string,int> mpp,window;
        for(auto& w:words)  mpp[w]++;
        for(int i=0;i<len;i++){
            int left=i,count=0;
            window.clear();
            for(int right=left;right+len<=n;right+=len){
                string word=s.substr(right,len);
                if(!mpp.count(word)){
                    left=right+len;
                    window.clear();
                    count=0;
                    continue;
                }
                window[word]++;
                count++;
                while(window[word]>mpp[word]){
                    string leftWord=s.substr(left,len);
                    window[leftWord]--;
                    count--;
                    left+=len;
                }
                while(count==words.size()){
                    res.push_back(left);
                    string leftWord=s.substr(left,len);
                    window[leftWord]--;
                    count--;
                    left+=len;
                }
            }
        }
        return res;
    }
};