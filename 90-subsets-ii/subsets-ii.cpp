class Solution {
public:
    void helper(int idx,vector<int> &nums,vector<vector<int>> &ans,vector<int> ds){
        ans.push_back(ds);

        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]){
                continue;
            }// avoiding the duplicates only this thing  is changes from the subsets probelm

            ds.push_back(nums[i]);
            // calling for next
            
            helper(i+1,nums,ans,ds);

            ds.pop_back();//while backtrack
            

        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        // sortinng is necessary becz if we did it all the duplicates cames togethere
        sort(nums.begin(),nums.end());
        helper(0,nums,ans,ds);

        return ans;
    }
};