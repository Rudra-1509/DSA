class Solution {
public:
    bool isValid(vector<int>& bloomDay,int m,int k,int curday){
        int count=0,streak=0;
        for(int day:bloomDay){
            if(curday>=day){
                streak++;
                if(streak==k){
                    count++;
                    streak=0;//reset
                }
            }
            else    streak=0;
        }
        return count>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left=*min_element(bloomDay.begin(),bloomDay.end());
        int right=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isValid(bloomDay,m,k,mid)){
                right=mid-1;
                ans=mid;
            }
            else    left=mid+1;
        }
        return ans;
    }
};