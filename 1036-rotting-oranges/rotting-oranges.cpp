class Solution {
public:
    int m,n;
    bool isValid(int i,int j){
        return (i>=0 && i<m && j>=0 && j<n);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;
        static vector<vector<int>> nav={{0,1},{0,-1},{1,0},{-1,0}};
        int time=-1,freshOranges=0;
        //push level 0 rotten oranges
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    freshOranges++;
            }
        }
        //if there are no rotten oranges or there are no oranges at all
        if(q.empty() && freshOranges)   return -1;
        if(q.empty())   return 0;
        //start bfs
        while(!q.empty()){
            int size=q.size();
            time++;
            for(int i=0;i<size;i++){
                pair<int,int> cur=q.front();q.pop();
                for(int i=0;i<4;i++){
                    int newr=cur.first+nav[i][0];
                    int newc=cur.second+nav[i][1];
                    if(isValid(newr,newc) && grid[newr][newc]==1){
                        q.push({newr,newc});
                        grid[newr][newc]=2;
                        freshOranges--;
                    }
                }
            }
        }


        return freshOranges? -1:time;
       
    }
};