class Solution {
public:
    void shiftValue(vector<int>& nums,int ind,int x){
        int n=nums.size();
        for(int i=n-1;i>ind;i--)
            nums[i]=nums[i-1];
        nums[ind]=x;
    }


    int maximumProduct(vector<int>& nums) {
        vector<int> largest(3,-1001);
        vector<int> smallest(2,1001);
        for(int x:nums){
            if(x>largest[0])
                shiftValue(largest,0,x);
            else if(x>largest[1])
                shiftValue(largest,1,x);
            else if(x>largest[2])
                shiftValue(largest,2,x);
            if(x<smallest[0]){
                smallest[1]=smallest[0];
                smallest[0]=x;
            }
            else if(x<smallest[1]){
                smallest[1]=x;
            }
        }
        return max(largest[0]*largest[1]*largest[2],largest[0]*smallest[0]*smallest[1]);
    }
};