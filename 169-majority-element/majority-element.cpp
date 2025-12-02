class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int winner=-1, count=0;
        for(int i:nums){
            if(count==0){
                winner=i;count++;
            }
            else if(i==winner)    count++;
            else    count--;
        }
        return winner;
    }
};