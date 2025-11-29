class Solution {
public:
    void reverse(vector<int>& nums,int i,int j){
        while(i<j){
            swap(nums[i],nums[j]);
            i++;j--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1)  return;
        int n=nums.size();
        int pivot=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivot=i;
                break;
            }
        }
        int j;
        if(pivot!=-1){ 
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[pivot]){
                j=i;
                break;
            }
        }
          swap(nums[j],nums[pivot]);
        }
        reverse(nums,pivot+1,n-1);
        //reverse(nums.begin()+pivot+1,nums.end());
    }
};