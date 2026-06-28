class Solution {
public:
    int m,n;
    int helper(int x,vector<vector<int>>& matrix){
        int i=0,j=n-1,ans=0;
        while(i<m && j>=0){
            if(matrix[i][j]<=x){
                ans+=j+1;
                i++;
            }
            else    j--;
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m=matrix.size(),n=matrix[0].size();
        int l=matrix[0][0],r=matrix[m-1][n-1];
        while(l<r){
            int mid=l+(r-l)/2;
            int count=helper(mid,matrix);
            if(count<k) l=mid+1;
            else        r=mid; 
        }
        return l;
    }
};