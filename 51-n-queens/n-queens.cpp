class Solution {
public:
    bool isSafe(int r,int c,vector<string>& board){
        int r1=r,c1=c;
        while(r1>=0){
            if(board[r1][c]=='Q')   return false;
            r1--;
        }
        r1=r;
        while(r1>=0 && c1>=0){
            if(board[r1][c1]=='Q')   return false;
            r1--;c1--;
        }
        r1=r,c1=c;
        while(r1>=0 && c1<board.size()){
            if(board[r1][c1]=='Q')   return false;
            r1--;c1++;
        }
        return true;
    }
    void helper(int r,int n,vector<vector<string>>& res,vector<string>& board){
        if(r==n){
            res.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(r,j,board)){
                board[r][j]='Q';
                helper(r+1,n,res,board);
                board[r][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> res;
        helper(0,n,res,board);
        return res;
    }
};