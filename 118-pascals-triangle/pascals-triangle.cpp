class Solution {
public:
    vector<int> generateRow(int n){
        vector<int> lev;
        int term=1;
        lev.push_back(term);
        for(int i=0;i<n;i++){
            term*=(n-i);
            term/=(i+1);
            lev.push_back(term);
        }
        return lev;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> lev;
        for(int i=0;i<numRows;i++){
            res.push_back(generateRow(i));
        }
        return res;
    }
};