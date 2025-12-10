class Solution {
public:
    bool isSafe(int r,int c,char x,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[i][c]==x || board[r][i]==x) return false;
        }
        int gridR=(r/3)*3;
        int gridC=(c/3)*3;
        for(int i=gridR;i<gridR+3;i++){
            for(int j=gridC;j<gridC+3;j++){
                if(board[i][j]==x)  return false;
            }
        }

        return true;
    }
    bool helper(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        if(isSafe(i,j,k+'0',board)){
                            board[i][j]=k+'0';
                            if(helper(board))   return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};