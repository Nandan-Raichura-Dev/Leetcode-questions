class Solution {
public:

    bool possible(vector<vector<char>> &board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[row][i]==c){
                return false;
            }

            if(board[i][col]==c){
                return false;
            }

            // checking 3*3 matrix for sudoko and there are 3 hosizon in the sudoku so thats why we divude it with 3 and multiply it 3 becz wee want the first row or col .

            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==c){
                return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>> &board){
        // we will find out the empty box to fill the sudoko and then if the one number from 1 to 9 is possibble than we will again call this func

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    

                    for(char c='1';c<='9';c++){
                        if(possible(board,i,j,c)){
                            board[i][j]=c;

                            if(solve(board)==true){// it will return true at the end when entire sudoku will be filled up entirly
                            return true; 
                            }else{
                                board[i][j]='.';
                            }
                        }
                      

                       
                    }
                      // if any of 1-9 numbers cant be filled up we will backtrack and return false;
                     return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};