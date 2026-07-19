class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hashLen=256;
        int hash[hashLen];
        int n=s.size();

        for(int i=0;i<hashLen;i++){
            hash[i]=-1;
        }

        int maxLen=0, l=0,r=0;

        while(r<n){
            // if the letter is already in the map
            if(hash[s[r]]!=-1){
                // if the currnt window(starting from the l comes after the letter ocuuring the twice, if the l is greater then the s[r] in the map, it means we can add that char even if it is existing in the sttack)
                if(hash[s[r]]>=l){// it comes under the same window
                    // we will start l form the one next psotion from the last occurence(stord in the hash)
                    l=hash[s[r]]+1;
                }

            }

            int len=r-l+1;
            maxLen=max(maxLen,len);
            hash[s[r]]=r;// updating it to the current index where this letter is gained seen, or it is benn first time seen 

            r++;
        }

        return maxLen;
    }
};