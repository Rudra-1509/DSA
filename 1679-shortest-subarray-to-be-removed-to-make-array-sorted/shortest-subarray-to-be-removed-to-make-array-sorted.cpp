class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1;
        while(l<n-1 && arr[l]<=arr[l+1])    l++;
        while(r>0 && arr[r]>=arr[r-1])      r--;
        if(l>r) return 0;
        int ans=min(n-l-1,r);
        for(int i=0;i<=l;i++){
            int j=lower_bound(arr.begin()+r,arr.end(),arr[i])-arr.begin();
            if(j==n)    break;
            ans=min(ans,j-i-1);
        }
        return ans;
    }
};