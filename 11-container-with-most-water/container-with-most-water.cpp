class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1,maxArea=0;
        while(l<=r){
            int w=r-l;
            int h=min(height[l],height[r]);
            maxArea=max(maxArea,h*w);
            if(h==height[l])    l++;
            else r--;
        }
        return maxArea;
    }
};