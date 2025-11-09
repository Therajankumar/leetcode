class Solution {
public:
    bool search(vector<vector<char>>& board, string word ,int row ,int col ,int ind ,int m ,int n){
    if(ind ==word.length()) return true;
    if(row <0 || col <0 || row==m || col==n || board[row][col] != word[ind] || board[row][col] =='!') return false;

    char c =board[row][col];
    board[row][col]='!';
    //up
    bool up=search(board ,word ,row -1,col ,ind+1 ,m,n);
    //down
      bool down=search(board ,word ,row +1,col ,ind+1 ,m,n);
    //left
      bool left=search(board ,word ,row ,col-1 ,ind+1 ,m,n);
    //right
      bool right=search(board ,word ,row ,col+1 ,ind+1 ,m,n);
    board[row][col]=c;
      return up || down || left || right;
}
    bool exist(vector<vector<char>>& board, string word) {
        int m =board.size();
    int n =board[0].size();
    int ind =0;
    for(int i=0;i<m ;i++){
        for(int j=0 ;j<n ;j++){
            if(board[i][j]==word[ind]){
                if(search(board,word,i,j,ind,m,n)){
                    return true;
                }
            }
        }
      
    } 
    return false;
    }
};