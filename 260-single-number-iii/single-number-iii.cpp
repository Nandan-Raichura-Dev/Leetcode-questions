class Solution {// bucket conceptt is used, in this we will sperate the numbers according to there set bits, if the set bit is 1, we will put in the 1st bucket and the zeroth bit into the 2nd bucket


public:
    vector<int> singleNumber(vector<int>& nums) {
        long xxor=0;

        // we want to eliminate the all numbers which are repeating, so by doin xxor, at the last we gget the xor of the number which are unique atleast one binary didgit will be uncommon from the both value
        
        for(int i=0;i<nums.size();i++){
            xxor=xxor^nums[i];
        }

        long rightMost=(xxor&(xxor-1))^xxor;// we will get the right most set bit, we take it out to decide which number will be put in the bucket 1 or 2

       
       int b1=0;
       int b2=0;
       
        for(int i=0;i<nums.size();i++){
            if(nums[i]&rightMost){// to check in the nums that the 1st bit is set or  and if it is non zero num we will store it in the b1 else in b2
            b1=b1^nums[i]; 

            }else{
                b2=b2^nums[i];
            }
        }


        return {b1,b2};
    }
};