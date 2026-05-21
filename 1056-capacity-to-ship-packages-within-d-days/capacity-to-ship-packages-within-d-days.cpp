class Solution {
public:
    bool helper(vector<int>& weights,int mid, int days){
        int d=1,sum=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]+sum > mid){
                d++;
                sum=weights[i];
            } 
            else    sum+=weights[i];
        }
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int right=accumulate(weights.begin(),weights.end(),0);
        int left=*max_element(weights.begin(),weights.end());
        int ans=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(helper(weights,mid,days)){
                ans=mid;
                right=mid-1;
            } 
            else    left=mid+1;
        }
        return ans;
    }
};