class Solution {
public:
    bool isValid(vector<int>& nums, int threshold,int div){
        int sum=0;
        for(int num:nums)
            sum+=(num+div-1)/div;
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1,right=*max_element(nums.begin(),nums.end());
        while(left<right){
            int mid=left+(right-left)/2;
            if(isValid(nums,threshold,mid))     right=mid;
            else    left=mid+1;
        }
        return left;
    }
};