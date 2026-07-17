class Solution {// in forward loop if the close bracket is more thrn ther open one, that meams there is missmatch of the brackts, and will reset it to the zero, becz until that part, the string is invalid, and vice versa in the case of the of backword loop
public:
    int longestValidParentheses(string s) {
        int open=0;
        int close=0;

        int maxi=0;

       for(char ch:s){
        if(ch=='('){
            open++;
        }else{
            close++;
        }

        if(close==open){
            int len=close*2;
            maxi=max(maxi,len);
        }else if(close>open){
            close=0;
            open=0;
        }
       }


       // backword check

        open=0;
        close=0;
       for(int i=s.size()-1;i>=0;i--){
            char ch=s[i];
            if(ch=='('){
            open++;
        }else{
            close++;
        }

        if(close==open){
            int len=close*2;
            maxi=max(maxi,len);
        }else if(open>close){
            close=0;
            open=0;
        }
       }
       return maxi;
    }
};