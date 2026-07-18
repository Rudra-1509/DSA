class Solution {
public:
    int scoreOfStudents(string s, vector<int>& answers) {
        vector<int> nums;
        vector<char> op;
        for(int i=0;i<s.size();i++){
            if(i & 1)   op.push_back(s[i]);
            else        nums.push_back(s[i]-'0');
        }
        int n=nums.size();

        vector<vector<unordered_set<int>>> dp(n,vector<unordered_set<int>>(n));
        for(int i=0;i<n;i++)    dp[i][i].insert(nums[i]);
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                for(int k=i;k<j;k++){
                    for(int a:dp[i][k]){
                        for(int b:dp[k+1][j]){
                            if(op[k]=='+' && a+b<=1000)     dp[i][j].insert(a+b);
                            else if(op[k]=='*' && a*b<=1000)     dp[i][j].insert(a*b);  
                        }
                    }
                }
            }
        }

        int summed=0,multied=nums[0];   //multied starts at the starting of a multi chain. if its a sum , move fwd
        for(int i=0;i<op.size();i++){
            if(op[i]=='*')
                multied*=nums[i+1];
            else{
                summed+=multied;
                multied=nums[i+1];
            }
        }
        summed+=multied;
        int res=0;
        for(int i=0;i<answers.size();i++){
            if(answers[i]==summed)  res+=5;
            else if(dp[0][n-1].count(answers[i]))   res+=2;
        }
        return res;

    }
};