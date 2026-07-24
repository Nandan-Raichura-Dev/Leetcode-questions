class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int r=0;
        int minLen=INT_MAX;
        int sum=0;

        while(r<nums.size()){
            sum+=nums[r];

            while(sum>=target){
                int len=r-l+1;
                minLen=min(minLen,len);
                // we will subract the current l pointer so we can calculate the furthere sum for new subarray
                sum-=nums[l];
                l++;
            }

           

            r++;
        }

        return minLen==INT_MAX?0:minLen;
    }
};