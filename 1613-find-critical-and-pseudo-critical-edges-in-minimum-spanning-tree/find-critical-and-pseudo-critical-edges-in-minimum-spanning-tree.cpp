class DSU {
private:
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        size.assign(n,1);
    }
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u]=find(parent[u]);
    }
    bool unite(int u,int v){
        int pu=find(u),pv=find(v);
        if(pu==pv)  return false;//same compo
        if(size[pu]>=size[pv]){
            size[pu]+=size[pv];
            parent[pv]=pu;
        }
        else{
            size[pv]+=size[pu];
            parent[pu]=pv;
        }
        return true;//unite successful
    }
};
class Solution {
public:
    using edge=pair<int,int>;
    int kruskal(int n,vector<vector<int>>& edges,int force,int skip){
        DSU dsu(n);
        int weight=0,edgesUsed=0;
        if(force!=-1){
            auto& e=edges[force];
            int u=e[0];
            int v=e[1];
            dsu.unite(u,v);
            weight+=e[2];
            edgesUsed++;
        }
        for(int i=0;i<edges.size();i++){
            if(i==force || i==skip) continue;
            auto& e=edges[i];
            if(dsu.unite(e[0],e[1])){
                weight+=e[2];
                edgesUsed++;
            }
            if(edgesUsed==n-1)  break;
        }
        if(edgesUsed<n-1)   return INT_MAX;
        return weight;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(2); //critical,pesudo-critical
        for(int i=0;i<edges.size();i++)
            edges[i].push_back(i);
        sort(edges.begin(),edges.end(),[](const vector<int>& a,const vector<int>& b){
            return a[2]<b[2];
        });
        //original
        int original=kruskal(n,edges,-1,-1);
        for(int i=0;i<edges.size();i++){
            //skip this edge
            int without=kruskal(n,edges,-1,i);
            if(without>original){
                res[0].push_back(edges[i][3]);
                continue;
            }
            //force this edge
            int with=kruskal(n,edges,i,-1);
            if(with==original)
                res[1].push_back(edges[i][3]);
        }
        return res;
    }
};