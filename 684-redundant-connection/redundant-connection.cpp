class DSU {
private: 
    vector<int> size,par;
public:
    DSU(int n){
        size.resize(n+1,1);
        par.resize(n+1);
        for(int i=1;i<=n;i++)
            par[i]=i;
    }

    int findPar(int u){
        if(u==par[u])   return u;
        return par[u]=findPar(par[u]);
    }

    bool unionBySize(int u,int v){
        int pu=findPar(u),pv=findPar(v);
        if(pu==pv)  return false;
        if(size[pu]>=size[pv]){
            par[pv]=pu;
            size[pu]+=size[pv];
        }   
        else{
            par[pu]=pv;
            size[pv]+=size[pu];
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        DSU dsu(V);
        for(auto& edge:edges){
            int u=edge[0],v=edge[1];
            if(!dsu.unionBySize(u,v))
                return {u,v};
        }
        return {};
    }
};