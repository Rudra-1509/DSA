class Solution {
public:
    vector<vector<int>> nav={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int oldColor){
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]!=oldColor) return;
        image[sr][sc]=color;
        dfs(image,sr+1,sc,color,oldColor);
        dfs(image,sr-1,sc,color,oldColor);
        dfs(image,sr,sc+1,color,oldColor);
        dfs(image,sr,sc-1,color,oldColor);
    }
    void bfs(vector<vector<int>>& image, int sr, int sc, int color,int oldColor){
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty()){
            pair<int,int> cur=q.front();q.pop();
            for(int i=0;i<4;i++){
                int newsr=cur.first+nav[i][0];
                int newsc=cur.second+nav[i][1];
                if(newsr>=0 && newsr<image.size() && 
                newsc>=0 && newsc<image[0].size() && 
                image[newsr][newsc]==oldColor){
                    q.push({newsr,newsc});
                    image[newsr][newsc]=color;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)    return image;
        int oldColor=image[sr][sc];
        bfs(image,sr,sc,color,oldColor);
        return image;
    }
};