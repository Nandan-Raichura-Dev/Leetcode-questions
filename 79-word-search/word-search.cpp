class Solution {
public:

    bool dfs(vector<vector<char>> &board,string &word,int row,int col,int idx){// here idx track the word to find in the string given to us (for eg s[0] can be the first letter of the given string)

    if(idx==word.size()){//if the recursion succesully reached at this stage where all the letters are matching and no othere letters left to compare, then we hit the base case and return true// success case
        return true;
    }

    if(row<0 || row >= board.size() || col<0 || col>= board[0].size()){
        return false;// contrls goes back to the parent recursive call
    }

    if(board[row][col]!=word[idx]){
        return false;
    }
    // if we reached till here it maens the cell is in the bound, reamins the elements to match , and the cell have letters matching to the letter to the word string so we move forward

    // we store the current cells letter so later on we can make it unticked or unvisted

    char ch=board[row][col];
    board[row][col]='#';

    // now we  check for the next cell, we have to pick one of the four side so i will use the recursion to do this, and try to find the next letter

    bool find= dfs(board,word,row-1,col,idx+1)||// we are suing idx+1 becz we are checking for the next letter
               dfs(board,word,row+1,col,idx+1)||
               dfs(board,word,row,col-1,idx+1)||
               dfs(board,word,row,col+1,idx+1);// if dfs(row-1, col, index+1) returns true ,C++ won't even evaluate the remaining three calls (down, left, right) because with ||, once one operand is true, the whole expression is true and there's no need to check further. This saves unnecessary work.   

               // we will repair the changes we have done '#' in order to make it visited, we are changing it while we are backtracking


               board[row][col]=ch;

               return find;// at each level we return the find 




    }

    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(dfs(board,word,i,j,0)){// if the cell gives true we will return true
                    return true;
                }
            }
        }
        return false;
    }
};