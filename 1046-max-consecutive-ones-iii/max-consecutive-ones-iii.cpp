class Solution {// brute force is by genrating all the subarray and then checking the conditions for the max consecutive 
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen=0;
        int l=0,r=0;
        int zero=0;
        
        while(r<nums.size()){
            if(nums[r]==0){
                zero++;
            }      

            while(zero>k){
                if(nums[l]==0){// triming up the zero so we can adjust our output currently proecees
                    zero--;
                    
                }
                l++;// if it is one we will also trim it
            }

            if(zero<=k){
                int len=r-l+1;
                maxLen=max(maxLen,len);

            }
            r++;// r will always move forward

        }

        return maxLen;
    }
};