class Fenwick {
private:
    int n;
    vector<int> bit;
public:
    Fenwick(int n){
        this->n=n;
        bit.assign(n+1,0);
    }
    void update(int i,int delta){
        for(;i<=n;i+=i&(-i)){
            bit[i]+=delta;
        }
    }
    int query(int i){
        int ans=0;
        for(;i>0;i-=i&(-i)){
            ans+=bit[i];
        }
        return ans;
    }
};
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<long long> temp;
        for(int x:nums){
            temp.push_back(x);
            temp.push_back(2LL*x);
        }
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());
        unordered_map<long long,int> mpp;
        for(int i=0;i<temp.size();i++)
            mpp[temp[i]]=i+1;
        Fenwick bit(mpp.size());
        for(int i=0;i<n;i++){
            int rank2=mpp[nums[i]*2LL];
            if(rank2>mpp.size())   continue;
            int smallerEq=bit.query(rank2);
            int greater=i-smallerEq;
            ans+=greater;
            bit.update(mpp[nums[i]],+1);           
        }
        return ans;
    }
};