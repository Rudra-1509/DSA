class DSU{
private:
    vector<int> par,size;
public:
    DSU(int n){
        par.resize(n,0);
        size.resize(n,1);
        for(int i=0;i<n;i++)
            par[i]=i;
    }
    int find(int u){
        if(u==par[u])   return u;
        return par[u]=find(par[u]);
    }
    bool unite(int u,int v){
        int pu=find(u),pv=find(v);
        if(pu==pv)  return true;
        if(size[pu]>=size[pv]){
            size[pu]+=size[pv];
            par[pv]=pu;
        }
        else{
            size[pv]+=size[pu];
            par[pu]=pv;
        }
        return false;
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> res(queries.size());
        DSU dsu(n);
        for(int i=0;i<nums.size()-1;i++){
            if(abs(nums[i]-nums[i+1])<=maxDiff) dsu.unite(i,i+1);
        }
        for(int i=0;i<queries.size();i++)
             res[i]=(dsu.find(queries[i][0])==dsu.find(queries[i][1]));
        return res;
    }
};