class Solution {
public:
    inline static vector<vector<int>> nav={{0,1},{0,-1},{1,0},{-1,0}};
    bool isSafe(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    bool helper(int i,int j,vector<vector<char>>& board, string& word,int index){
        if(board[i][j] != word[index])      return false;
        if(index == word.size()-1)      return true;
        if(word.size()==1 && board[i][j]==word[index])  return true;
        board[i][j]='.';
        for(auto d: nav){
            int ni=i+d[0],nj=j+d[1];
            if(isSafe(ni,nj,board.size(),board[0].size()) && board[ni][nj]!='.')
                if(helper(ni,nj,board,word,index+1)){
                    board[i][j]=word[index];
                    return true;
                }
        }
        board[i][j]=word[index];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0)    return false;

    unordered_map<char,int> boardFreq;
    unordered_map<char,int> wordFreq;

    int m = board.size();
    int n = board[0].size();

    for(auto &row : board){
        for(char c : row)
            boardFreq[c]++;
    }

    for(char c : word){
        wordFreq[c]++;

        if(wordFreq[c] > boardFreq[c])
            return false;
    }

    // reverse if last char is rarer
    if(boardFreq[word[0]] > boardFreq[word.back()]){
        reverse(word.begin(), word.end());
    }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(helper(i,j,board,word,0))    return true;
                }
            }
        }
        return false;
    }
};