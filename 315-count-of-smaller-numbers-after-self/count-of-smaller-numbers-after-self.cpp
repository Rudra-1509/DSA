class Fenwick {
private:
    int n;
    vector<int> bit;
public:
    Fenwick(int n){
        this->n=n;
        bit.assign(n+1,0);
    }    
    int query(int i){
        int ans=0;
        while(i>0){
            ans+=bit[i];
            i-=i&(-i);
        }
        return ans;
    }
    void update(int i,int delta){
        while(i<=n){
            bit[i]+=delta;
            i+=i&(-i);
        }
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());
        unordered_map<int,int> mpp;
        for(int i=0;i<temp.size();i++)
            mpp[temp[i]]=i+1;
        Fenwick bit(mpp.size());
        vector<int> res(n,0);
        for(int i=n-1;i>=0;i--){
            int rank=mpp[nums[i]];
            int ans=bit.query(rank-1);
            res[i]=ans;
            bit.update(rank,+1);
        }
        return res;
    }
};