class Solution {
public:
    void rev(vector<int>& arr){
        int l=0,r=arr.size()-1;
        while(l<r){
            swap(arr[l],arr[r]);
            l++;r--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<m;i++)
            rev(matrix[i]);
    }
};