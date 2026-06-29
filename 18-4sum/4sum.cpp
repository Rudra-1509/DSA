class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1])   continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1])   continue;
                int left=j+1,right=n-1;
                while(left<right){
                    long long rem=0LL+nums[left]+nums[right]+nums[i]+nums[j]-target;
                    if(rem>0)        right--;
                    else if(rem<0)   left++;
                    else {
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;right--;
                        while(nums[left]==nums[left-1] && left<right) left++;
                        while(nums[right]==nums[right+1] && left<right) right--;
                    }
                }
            }
        }
        return res;
    }
};