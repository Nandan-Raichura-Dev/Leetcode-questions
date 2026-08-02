class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int cnt=0;
        double val=(double)a/b;
        
        vector<int> norvelith = nums;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int even=0;
            int odd=0;

            for(int j=i;j<n;j++){
                if(nums[j]%2==0){
                   even++;
                }else{
                    
                     odd++;
                }

                if(odd==0){
                    // y must be > 0 to be valid; skip
                    continue;
                }

               
                double ratio=(double)even/odd;
                if(ratio<=val){
                    cnt++;
                
                }
            }
        }
            return cnt;
        
    }
};