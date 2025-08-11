class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int oldColor){
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]!=oldColor) return;
        image[sr][sc]=color;
        dfs(image,sr+1,sc,color,oldColor);
        dfs(image,sr-1,sc,color,oldColor);
        dfs(image,sr,sc+1,color,oldColor);
        dfs(image,sr,sc-1,color,oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)    return image;
        int oldColor=image[sr][sc];
        dfs(image,sr,sc,color,oldColor);
        return image;
    }
};