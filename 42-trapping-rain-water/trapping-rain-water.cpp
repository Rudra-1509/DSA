class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1,lmax=0,rmax=0,water=0;
        while(left<right){
            if(height[left]<=height[right]){
                if(height[left]>=lmax)  lmax=height[left];
                water+=lmax-height[left];
                left++;
            }
            else{
                if(height[right]>=rmax) rmax=height[right];
                water+=rmax-height[right];
                right--;
            }
        }
        return water;
    }
};