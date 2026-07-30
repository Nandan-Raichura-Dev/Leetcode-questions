class Solution {// brute force:recurive solution
public:
    int jump(vector<int>& nums) {
        int jumps=0; 
        int n=nums.size();
        int l=0;
        int r=0;

        while(r<n-1){
            int farthest=0;

            for(int i=l;i<=r;i++){
                farthest=max(farthest,i+nums[i]);
            }
            jumps++;
            l=r+1;
            r=farthest;
        }

        return jumps;
    }
};