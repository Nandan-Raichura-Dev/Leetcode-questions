class Solution {// same probelm as the binary subarray with sum
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       map<int,int> hash;
      hash[0]=1;// intially storeing 
      int sum=0;
      int cnt=0;

      for(int i=0;i<nums.size();i++){
        sum+=nums[i]%2;
        int diff=sum-k;
        cnt+=hash[diff];
        hash[sum]++;
      }

    return cnt;
    }
};