class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int winner=-1,count=0;
        for(int x: nums){
            if(x==winner)   count++;
            else if(count==0){
                count=1;
                winner=x;
            }   
            else count--;
        }
        return winner;
    }
};