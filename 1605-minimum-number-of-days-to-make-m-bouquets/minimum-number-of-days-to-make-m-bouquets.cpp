class Solution {
public:
    bool isValid(vector<int>& bloomDay,int m,int k,int day){
        int count=0;
        vector<int> vec;
        for(int num:bloomDay){
            if(day>=num){
                vec.push_back(num);
                if(vec.size()==k){
                    count++;
                    vec.clear();
                }
            }
            else    vec.clear();    
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
            else            left=mid+1;
        }
        return ans;
    }
};