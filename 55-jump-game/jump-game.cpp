class Solution {// we are being greedy be jumping maximum we can, if there are only positive numbers, we will always reach at the zero

public:
    bool canJump(vector<int>& nums) {
        int maxIdx=0;/// it states the maximmum jummp we can do till now and if it goes out size the size of arrray it means we can reach the end definetly

        for(int i=0;i<nums.size();i++){
            // if our i goes beyond the maximum index, it means we have crossed the zero,, then we return false
            if(i>maxIdx){
                return false;
            }

            maxIdx=max(maxIdx,nums[i]+i);
        }

        return true;
    }
};