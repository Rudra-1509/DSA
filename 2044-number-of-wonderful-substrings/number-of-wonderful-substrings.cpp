class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans=0;
        int mask=0;
        unordered_map<int,int> mpp;
        mpp[0]=1;
        for(char ch:word){
            mask^=(1<<(ch-'a'));
            if(mpp.count(mask)) ans+=mpp[mask];

            for(int i=0;i<10;i++){
                int x=1<<i;
                int prev=mask^x;
                if(mpp.count(prev))     ans+=mpp[prev];
            }

            mpp[mask]++;
        }
        return ans;
    }
};