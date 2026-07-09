class Solution {
public:
    int divide(int dividend, int divisor) {
        
         if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        if(dividend==divisor){
            return 1;
        }

        bool sign=true;

        if(dividend>=0 && divisor<0){
            sign=false;
        }
        else if(dividend<=0 && divisor>0){
            sign=false;
        }


        // we will divide the diveidend with its divisor with 2 thi power(1..2..3) nd its goes on

        long n=abs((long)dividend);
        long d=abs((long)divisor);

        

        long quotient=0;// this we will be the variable which will store the 2(power) value, that has benn tanken out of the dividend or while process

        while(n>=d){// we can still take out
        int cnt=0;// it is power

        while((cnt<31)&&n>=(d<<(cnt+1))){ //divisor * 2(power);
            cnt++;
        }
        quotient+=1L<<cnt;
        n-=(d<<cnt);


        

        } 

        if(quotient==(1<<31)&&sign){
            return INT_MAX;
        }

        if(quotient==(1<<31)&&!sign){
            return INT_MIN;
        }

        
        return sign?quotient:-quotient;

    }
};