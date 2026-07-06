class DSU {
private:
    vector<int> par,size;
public:
    DSU(int n){
        size.resize(n+1,1);
        par.resize(n+1,-1);
        for(int i=1;i<=n;i++)
            par[i]=i;
        size[0]=-1;
    }

    int find(int u){
        if(par[u]==u)   return u;
        return par[u]=find(par[u]);
    }

    bool unite(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv)  return true;//same component or cycle
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> candidate1,candidate2;
        int n=edges.size();
        DSU dsu(n);
        vector<int> par(n+1,0);
        for(auto& edge:edges){
            int u=edge[0],v=edge[1];
            if(par[v]==0)   par[v]=u;
            else{
                candidate1={par[v],v};
                candidate2=edge;
                edge[1]=-1;
            }
        }
        for(auto& edge:edges){
            int u=edge[0],v=edge[1];
            if(v==-1)   continue;
            if(dsu.unite(u,v)){
                if(candidate1.empty())  return edge;
                else    return candidate1;
            }
        }
        return candidate2;
    }
};