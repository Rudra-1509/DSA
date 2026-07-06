class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int candidate1=-1,candidate2=-1,count1=0,count2=0;
        for(int& x:nums){
            if(x==candidate1)   count1++;
            else if(x==candidate2)  count2++;
            else if(count1==0){
                candidate1=x;
                count1=1;
            }  
            else if(count2==0){
                candidate2=x;
                count2=1;
            }
            else{
                count1--;count2--;
            }
        }
        count1=count2=0;
        for(int& x:nums){
            if(x==candidate1)   count1++;
            else if(x==candidate2)   count2++;
        }
        int lim=nums.size()/3;
        if(count1>lim)    res.push_back(candidate1);
        if(count2>lim)    res.push_back(candidate2);
        return res;
    }
};