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
        for(;i>0;i-=i&(-i))
            ans+=bit[i];
        return ans;
    }
    void update(int i,int delta){
        for(;i<=n;i+=i&(-i))
            bit[i]+=delta;
    }
};
class Solution {
public:
    const int MOD=1e9+7;
    int createSortedArray(vector<int>& instructions) {
        int ans=0,n=instructions.size();
        int maxi=*max_element(instructions.begin(),instructions.end());
        Fenwick bit(maxi);
        for(int i=0;i<n;i++){
            int x=instructions[i];
            int smaller=bit.query(x-1);
            int greater=i-bit.query(x);
            ans=(ans+min(smaller,greater))%MOD;
            bit.update(x,+1);
        }
        return ans;
    }
};