class Solution {
private:
    int m,n;
    int lessEq(int x,vector<vector<int>>& matrix){
        int i=0,j=n-1,ans=0;
        while(i<n && j>=0){
            if(matrix[i][j]<=x){
                ans+=j+1;
                i++;
            } 
            else    j--;
        }
        return ans;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m=matrix.size(),n=matrix[0].size();
        int l=matrix[0][0],r=matrix[m-1][n-1];
        while(l<r){
            int mid=l+(r-l)/2;
            if(lessEq(mid,matrix)>=k)   r=mid;
            else    l=mid+1;
        }
        return l;
    }
};