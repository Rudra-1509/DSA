class Solution {
public:
    bool isPal(string s,int l,int r){
        while(l<r){
            if(s[l]!=s[r])  return false;
            l++;r--;
        }
        return true;
    }
    void helper(string s,int ind,vector<vector<string>>& res,vector<string>& path){
        if(ind==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPal(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                helper(s,i+1,res,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        helper(s,0,res,path);
        return res;
    }
};