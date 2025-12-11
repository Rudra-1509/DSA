class Solution {
public:
    bool helper(string s,int ind,unordered_set<string>& dict,vector<int>& dp){
        if(ind==s.size())    return true;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=ind;i<s.size();i++){
            string left=s.substr(ind,i-ind+1);
            if(dict.count(left)){
                if(helper(s,i+1,dict,dp))  return dp[ind]=1;
            }
        }
        return dp[ind]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size(),-1);
        helper(s,0,dict,dp);
        return dp[0];
    }
};