class Solution {
public:
    bool isPal(string w){
        int l=0,r=w.size()-1;
        while(l<r){
            if(w[l]!=w[r])  return false;
            l++;r--;
        }
        return true;
    }

    void helper(string s,int start,vector<string>& path,vector<vector<string>>& res,vector<vector<bool>>& dp){
        if(start==s.size()){
            res.push_back(path);
            return;
        }
        for(int end=start;end<s.size();end++){
            // string w=s.substr(start,end-start+1);
            if(dp[start][end]){
            // if(isPal(w)){
                // path.push_back(w);
                path.push_back(s.substr(start,end-start+1));
                helper(s,end+1,path,res,dp);
                path.pop_back();
            }
        }
    }

    void fillDP(string s,vector<vector<bool>>& dp){
        int n=s.size();
        for(int i=0;i<n;i++)    dp[i][i]=true;
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]==s[j] && (len<=3 || dp[i+1][j-1]))
                    dp[i][j]=true;
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        fillDP(s,dp);
        helper(s,0,path,res,dp);
        return res;
    }
};