class Solution {
public:
    string encode(string word){
        vector<int> frq(26,0);
        for(char ch:word)
            frq[ch-'a']++;
        string res="";
        for(int i=0;i<26;i++)
            res+=(char)(i+'a')+to_string(frq[i]);
        return res;

    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mpp;
        for(string word:strs){
            mpp[encode(word)].push_back(word);
        }
        for(auto it:mpp)
            res.push_back(it.second);
        return res;
    }
};