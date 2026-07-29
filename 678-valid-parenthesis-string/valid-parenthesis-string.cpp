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