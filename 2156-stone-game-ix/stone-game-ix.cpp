class Solution {
public:
    bool helper(vector<int> count,int n,int k){
        if(count[k]<=0)  return false;
        count[k]--;
        int sum=k;
        for(int i=1;i<n;i++){
            if(count[1]>0 && (sum+1)%3>0){
                count[1]--;
                sum+=1;
            }
            else if(count[2]>0 && (sum+2)%3>0){
                count[2]--;
                sum+=2;
            }
            else if(count[0]>0 && sum%3>0)
                count[0]--;
            else    return i & 1;
        }
        return false;
    }

    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
        vector<int> count(3,0);
        for(int& stone:stones)
            count[stone%3]++;
        return helper(count,n,1)||helper(count,n,2);
    }
};