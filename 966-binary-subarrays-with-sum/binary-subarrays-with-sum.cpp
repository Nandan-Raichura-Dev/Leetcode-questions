class Solution {// we cant find the nums of sub array with goal becz it is more complicated, so what  wedo is, we find <= goal, so we can just do it properly also this is almost same question context as ans subarray count with sum K, 
public:
        int atMost(vector<int>& nums, int goal){
        int l=0,r=0;
        int cnt=0;
        int sum=0;

        while(r<nums.size()){
            if(goal<0){
                return 0;
            }
            sum+=nums[r];
            // if the sum is exceding the goal, we will trim our window from the left

            while(sum>goal){
                sum-=nums[l];
                l++;

            
            }

            // so if we have goal under the limit given we will increase the cnt, we will consider all the subarray which are less then or equal to the goal, 

            cnt=cnt+(r-l+1);
            r++;
        }

        return cnt;
        }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return atMost(nums,goal)-atMost(nums,goal-1);
    }
};