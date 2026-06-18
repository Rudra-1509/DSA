class Solution {
public:
    void helper(string s,int ind,unordered_set<string>& dict,string sent,vector<string>& res){
        if(ind==s.size()){
            sent.pop_back();
            res.push_back(sent);
            return;
        }
        for(int i=ind;i<s.size();i++){
            string word=s.substr(ind,i-ind+1);
            if(dict.count(word)){
                int curInd=sent.size()-1;
                helper(s,i+1,dict,sent+word+' ',res);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<string> res;
        string sent="";
        helper(s,0,dict,sent,res);
        return res;
    }
};