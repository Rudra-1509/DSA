class Solution {
public:
    bool isPossible(vector<int>& weights, int days,int capacity){
        int sum=0,dayCount=1;
        for(int weight:weights){
            sum+=weight;
            if(sum>capacity){
                dayCount++;
                sum=weight;
            }
        }
        return  dayCount<=days; 
    }
    int shipWithinDays(vector<int>& weights, int days) {
     int left=*max_element(weights.begin(),weights.end());
     int right=accumulate(weights.begin(),weights.end(),0);
     while(left<right){
        int mid=left+(right-left)/2;
        if(isPossible(weights,days,mid))    right=mid;
        else    left=mid+1;    
     }   
     return left;
    }
};