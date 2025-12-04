class Solution {
public:
    int revCount=0;
    void merge(vector<int>& nums,int l,int mid,int r){
        int p=l,q=mid+1;
        for(;p<=mid;p++){
            while(q<=r && (long long)nums[p]>2LL*nums[q])    q++;
            revCount+=q-mid-1;    
        }
        vector<int> temp(r-l+1);
        int i=l,j=mid+1,k=0;
        while(i<=mid && j<=r){
            if(nums[i] <= nums[j])  temp[k++]=nums[i++];
            else                    temp[k++]=nums[j++];
        }
        while(i<=mid)   temp[k++]=nums[i++];
        while(j<=r) temp[k++]=nums[j++];

        for(int i=l;i<=r;i++)  nums[i]=temp[i-l];
    }
    void divide(vector<int>& nums,int l,int r){
        if(l>=r) return;
        int mid=l+(r-l)/2;
        divide(nums,l,mid);
        divide(nums,mid+1,r);

        merge(nums,l,mid,r);
    }
    int reversePairs(vector<int>& nums) {
        divide(nums,0,nums.size()-1);
        return revCount;
    }
};