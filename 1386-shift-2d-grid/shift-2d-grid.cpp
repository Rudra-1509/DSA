class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> res(m,vector<int>(n,0));
        k=k%(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int newIndex=i*n+j+k;
                int newCol=newIndex%n;
                int newRow=(newIndex/n)%m;
                res[newRow][newCol]=grid[i][j];

            }
        }
        return res;
    }
};