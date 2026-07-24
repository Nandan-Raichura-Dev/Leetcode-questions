class Solution {// brute is to genrate all teh substring and then do some oprerations
public:
    string minWindow(string s, string t) {
        int l=0;
        int r=0;
        int cnt=0;
        int sIdx=-1;
        int minLen=INT_MAX;

        map<char,int> mpp;

        for(int i=0;i<t.size();i++){// inserting all the leeters in the map , so we colud know the freq and based on that we can do opreations furthere
            mpp[t[i]]++;
        }

        while(r<s.size()){
            mpp[s[r]]--;
            if(mpp[s[r]]>=0){// it means it already exist and we had added it from the string t
            cnt++;
          
            }// if we have seen it in the s then we will take it out, so we dont increase our cnt furthere when we see the same letter

            while(cnt==t.size()){// we have all eelements needed in the present window
            // first we will find out the leenght of that substring having all req char
            if((r-l+1)<minLen){
                minLen=r-l+1;
                sIdx=l;
            }
            // nd now we will try to trim down the substring or the window we got, becz we want the minimum substring, we will shrink it from the left

            mpp[s[l]]++;
            // if we got the element'freqency more then 0 , it means it is agianed puted back to the t string, (only for rembering) 
            if(mpp[s[l]]>0){
                cnt--;
            }
                l++;
            }
            r++;

            
        }

        return sIdx==-1?"":s.substr(sIdx,minLen);
    }
};