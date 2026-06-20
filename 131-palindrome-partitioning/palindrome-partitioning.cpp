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

    void helper(string s,int start,vector<string>& path,vector<vector<string>>& res){
        if(start==s.size()){
            res.push_back(path);
            return;
        }
        for(int end=start;end<s.size();end++){
            string w=s.substr(start,end-start+1);
            if(isPal(w)){
                path.push_back(w);
                helper(s,end+1,path,res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        helper(s,0,path,res);
        return res;
    }
};