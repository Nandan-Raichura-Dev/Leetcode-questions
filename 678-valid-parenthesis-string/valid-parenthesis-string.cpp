class Solution {// brute force is to try the all possible solution for the givene string, through recuresion, , optimal consist of the range instead of the count
public:
    bool checkValidString(string s) {
        int min=0;
        int max=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                min++;
                max++;
            }else if(s[i]==')'){
                min=min-1;
                max=max-1;
            }else{// *

            min=min-1;// rannge starts 
            max=max+1;

            }
            if(min<0){// we wdont need to add the 
                min=0;
            }

            if(max<0){// noo range in positive side
                return false;
            }
        }

        if(min==0){
            return true;
        }
        return false;
    }
};



// recursive approch
// class Solution {
// public:
//     // index -> current position in string
//     // openCount -> number of unmatched '(' so far
//     bool solve(string &s, int index, int openCount){
        
//         // if at any point open count goes negative, 
//         // it means too many ')' with nothing to match -> invalid
//         if(openCount < 0){
//             return false;
//         }

//         // reached end of string, valid only if everything is matched
//         if(index == s.size()){
//             return openCount == 0;
//         }

//         char ch = s[index];

//         if(ch == '('){
//             // must open a bracket
//             return solve(s, index+1, openCount+1);
//         }
//         else if(ch == ')'){
//             // must close a bracket
//             return solve(s, index+1, openCount-1);
//         }
//         else{
//             // ch == '*', try all 3 possibilities
//             bool asOpen  = solve(s, index+1, openCount+1); // treat * as '('
//             bool asClose = solve(s, index+1, openCount-1); // treat * as ')'
//             bool asEmpty = solve(s, index+1, openCount);   // treat * as ""

//             // valid if ANY of the 3 choices works
//             return asOpen || asClose || asEmpty;
//         }
//     }

//     bool checkValidString(string s) {
//         return solve(s, 0, 0);
//     }
// };