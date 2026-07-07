class Solution {
public:
    string decodeString(string s) {
        stack<int> stNum;
        stack<string> strLetter;

        int num=0;
        string curr="";// to storethe current value

        // until we not find the '[' we will store the letter and the digit comes in our way
        for(char c:s){
            if(isdigit(c)){// if the c is digit we will addit in the num
            num=(num*10)+(c-'0');
            }
            else if(c=='['){// new progress start set everyy thing into the zero
                stNum.push(num);
                strLetter.push(curr);
                num=0;
                curr="";// new string or progress start so we make it to the zero
            }else if(c==']'){// let process the string insde  ths bracket
               
                int repeatCount=stNum.top();
                stNum.pop();
                string prevStr=strLetter.top();
                strLetter.pop();

                 string temp="";

                for(int i=0;i<repeatCount;i++){
                    temp+=curr;// it will repeat the string for the required num of times
                }

                curr=prevStr+temp;
            }else{// it is simple char
              curr=curr+c;

            }

        }

        return curr;


    }
};