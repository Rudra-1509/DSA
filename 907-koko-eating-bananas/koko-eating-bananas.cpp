class Solution {
public:
    bool helper(vector<int>& piles,int h,int mid){
        long long hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=(piles[i]+mid-1)/(long long)mid;
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(helper(piles,h,mid)){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};