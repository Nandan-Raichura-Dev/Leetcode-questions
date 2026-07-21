class Solution {// brute solutioj will be to genrate all the substring and then checking it   we will change the char which have less freq, if we chnage the char which have hihger freq, we end up havong more work, so twe will do less work by changing it, and the numsber of changes should be under the k
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26,0);
        int l=0,r=0;
        int maxFreq=0;
        int maxLen=0;

        while(r<s.size()){

            // first we will just update the freq
            hash[s[r]-'A']++;
            maxFreq=max(maxFreq,hash[s[r]-'A']);

            // now we will check if the current window is valid or not if not we will trim the window from the left, until it beomes the vaild 

            while(((r-l+1)-(maxFreq))>k){// it means the changes required in this window is more then k , so will trim it up

            hash[s[l]-'A']--;
            l++;

            // we will also update the max freq fur the furthere usecase


            for(int i=0;i<26;i++){
                maxFreq=max(maxFreq,hash[i]);
            }

            }

          if(((r-l+1)-(maxFreq))<=k){// changes required is under the k or equal to k
                maxLen=max(maxLen,(r-l+1));
          }

            r++;

        }

        return maxLen;
    }
};