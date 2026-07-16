class Solution {
public:
    int m,n;
    bool isValid(int i,int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    bool moveNext(int i,int j,int di,int dj,vector<vector<char>>& board, string word){
        for(int k=0;k<word.size();k++){
            if(!isValid(i,j))   return false;
            if(board[i][j]!=' ' && board[i][j]!=word[k])    return false;
            i=i+di;
            j=j+dj;
        }
        return ((isValid(i,j) && board[i][j]=='#') || !isValid(i,j));
    }

    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='#')    continue;
                bool ans=false;
                if(j==0 || board[i][j-1]=='#')      ans=ans || moveNext(i,j,0,1,board,word); //right
                if(ans)     return true;
                if(i==0 || board[i-1][j]=='#')      ans=ans || moveNext(i,j,1,0,board,word); //down
                if(ans)     return true;
                if(j==n-1 || board[i][j+1]=='#')    ans=ans || moveNext(i,j,0,-1,board,word); //left
                if(ans)     return true;
                if(i==m-1 || board[i+1][j]=='#')    ans=ans || moveNext(i,j,-1,0,board,word); //up
                if(ans)     return true;
            }
        }
        return false;
    }
};