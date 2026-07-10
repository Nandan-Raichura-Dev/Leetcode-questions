class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());// this grps the repating number in continous mannnerr
        for(int i=1;i<nums.size();i+=3){
            if(nums[i]!=nums[i-1]){
                return nums[i-1];
            }
        }

        return nums[n-1];
    }
};