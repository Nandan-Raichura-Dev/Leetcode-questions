class Solution {
public:// brute force is to genrate all the subarrays and thenc check it, for optimal one, we willuse the map, and we cant find the subbraay with== k becz with stnadard sliding window we cant cover all the subarray with k diff int, so we will find out for the less than k and then we aill out for the k-1, and then subract it , so we can get the ans

    int atMax(vector<int> &nums,int k){
        int l=0;
        int r=0;
        int cnt=0;
        
        map<int,int> mpp;

        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>k){// trimig down the window
                mpp[nums[l]]--;

                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }

            cnt=cnt+(r-l+1);// we will include all the subarrays for that window so we add the length
            r++;
        }
        return cnt;

    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMax(nums,k)-atMax(nums,k-1);
    }
};