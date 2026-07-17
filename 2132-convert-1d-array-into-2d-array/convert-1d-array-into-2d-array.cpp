class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size()!=m*n)    return {};
        vector<vector<int>> res(m,vector<int>(n));
        int i=0,j=0;
        for(int k=0;k<original.size();k++){
            res[i][j]=original[k];
            if(j==n-1){
                j=0;
                i++;
            }
            else j++;
        }
        return res;
    }
};