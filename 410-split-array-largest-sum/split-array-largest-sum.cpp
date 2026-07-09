class Solution {
public:
    bool isValid(vector<int>& nums,int mid, int k){
        int sticks=0,sum=0;
        for(int x:nums){
            sum+=x;
            if(sum>mid){
                sticks++;
                sum=x;
            }
        }
        return sticks+1<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int left=*max_element(nums.begin(),nums.end());
        int right=accumulate(nums.begin(),nums.end(),0);
        while(left<right){
            int mid=left+(right-left)/2;
            if(isValid(nums,mid,k)) right=mid;
            else left=mid+1;
        }
        return left;
    }
};