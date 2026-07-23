class Solution {
public:
    int maxVowels(string s, int k) {
        int l=0;
        int r=0;

        int maxCount=0;
        int len=0;
        int vc=0;

        while(r<s.size()){

            // cheecking if it is under the size or not
            if(len<k){

            // checkingg it is vowel or not 
            if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u'){
                vc++;
                maxCount=max(maxCount,vc);
                r++;
                len++;
            }else{
                r++;
                len++;
            }

            }else{
             
                if(s[l]=='a' || s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u'){
                    vc--;
                }
                l++;
                if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u'){
                    vc++;
                    maxCount=max(maxCount,vc);
                }

                   r++;
            }
        }

        return maxCount;
    }
};