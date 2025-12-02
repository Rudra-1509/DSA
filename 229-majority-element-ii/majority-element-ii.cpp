class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0,count2=0,pw1=-1,pw2=-1,n=nums.size();
        for(int x: nums){
            if(x==pw1)          count1++;
            else if(x==pw2)     count2++;
            else if(count1==0)  pw1=x,count1=1;
            else if(count2==0)  pw2=x,count2=1;
            else                count1--,count2--;
        }

        count1=count2=0;
        for(int x:nums){
            if(x==pw1)  count1++;
            else if(x==pw2)  count2++;
        }
        vector<int> res;
        if(count1 > n/3)    res.push_back(pw1);
        if(count2 > n/3)    res.push_back(pw2);
        return res;    
    }
};