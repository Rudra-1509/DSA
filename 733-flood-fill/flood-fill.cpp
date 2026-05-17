class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)    return image;
        int clr=image[sr][sc];
        queue<pair<int,int>> q;
        vector<vector<int>> nav={{0,1},{0,-1},{1,0},{-1,0}};
        q.push({sr,sc});
        image[sr][sc]=-1;
        while(!q.empty()){
            auto [r,c]=q.front();q.pop();
            for(int i=0;i<4;i++){
                int nr=r+nav[i][0];
                int nc=c+nav[i][1];
                if(nr>=0 && nr<image.size() && nc>=0 && nc<image[0].size() 
                    && image[nr][nc]!=-1 && image[nr][nc]==clr){
                    q.push({nr,nc});
                    image[nr][nc]=-1;
                }
            }
        }
        for(int i=0;i<image.size();i++){
            for(int j=0;j<image[0].size();j++){
                if(image[i][j]==-1)
                    image[i][j]=color;
            }
        }
        return image;
    }
};