class Solution {
public:
    string decodeAtIndex(string s, int k) {
        // first taking out the  size of the string after the expanding it  so that we can do the opreations on the our orignal string

        long long size=0;

        for(char ch:s){
            if(isalpha(ch)){
                size++;
            }else{
                // it is digit
                size=size*(ch-'0'); 
                
                 }
        }

        // looping backwords becz we have to firstky consider the numbers to process the whole string

        for(int i=s.size()-1;i>=0;i--){
            k=k%size;// findin out the size of the gievn string with repect to the formula and aviding the duplicates, thats why i modulo it with the size, so we can know the elination of reapted string , if k%size=0 then we are the index , which is the deamanded

            if(k==0 && isalpha(s[i])){
                return string(1,s[i]);
            }else{
                // we will reduse the sizeof the string 
                if(isalpha(s[i])){
                    size=size-1;
                }else{
                    size=size/(s[i]-'0');
                }
            }

        }
            return "";

    }
};