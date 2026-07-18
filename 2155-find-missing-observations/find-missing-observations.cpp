class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=accumulate(rolls.begin(),rolls.end(),0);
        int left=(rolls.size()+n)*mean-sum;
        if(left<n || left>n*6)  return {};
        vector<int> res(n,left/n);
        int rem=left%n;
        for(int i=0;i<rem;i++)
            res[i]++;
        return res;
    }
};