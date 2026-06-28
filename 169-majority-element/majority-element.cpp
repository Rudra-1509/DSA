class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int winner=-1,count=0;
        for(int x: nums){
            if(count==0)    winner=x;
            if(winner==x)   count++;
            else count--;
        }
        return winner;
    }
};