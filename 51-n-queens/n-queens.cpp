class Solution {
public:
    bool isSafe(vector<string>& board,int row,int col){
        int i=row,j=col;
        while(j>=0){
            if(board[row][j]=='Q')  return false;
            j--;
        }
        while(i>=0){
            if(board[i][col]=='Q')  return false;
            i--;
        }
        i=row;
        j=col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q')    return false;
            i--;
            j--;
        }
        i=row;
        j=col;
        while(i<board.size() && j>=0){
            if(board[i][j]=='Q')    return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(vector<string>& board,int ind,vector<vector<string>>& res){//ind->col
        if(ind==board.size()){
            res.push_back(board);
            return;
        }
        for(int i=0;i<board.size();i++){ //i->row
            if(isSafe(board,i,ind)){
                board[i][ind]='Q';
                helper(board,ind+1,res);
                board[i][ind]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n,string(n,'.'));
        helper(board,0,res);
        return res;
    }
};