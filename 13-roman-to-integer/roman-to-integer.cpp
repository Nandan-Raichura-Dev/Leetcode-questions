class Solution {
public:
    int romanToInt(string s) {
        long long ans=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='I'){
                ans+=1;
               if(i+1<s.size() && s[i+1]=='V' || s[i+1]=='X'){
                ans-=2;// in order to make it required number , we are subracting two becz we have added 1 in advance , and aanother 1 we have to subract

               }
            }else if(ch=='V'){
                ans+=5;
                
            }
            else if(ch=='X'){
                ans+=10;

                 if(i+1<s.size() && s[i+1]=='L' || s[i+1]=='C'){
                        ans-=20;
                 }

            }else if(ch=='L'){

                ans+=50;


            }else if(ch=='C'){
                ans+=100;
                 if(i+1<s.size() && s[i+1]=='D' || s[i+1]=='M'){
                    ans-=200;
                 }

            }else if(ch=='D'){
                ans+=500;

            }else if(ch=='M'){
                ans+=1000;

            }
        }


        return ans;
    }
};