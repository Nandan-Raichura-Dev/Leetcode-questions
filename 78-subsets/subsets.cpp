class Solution {
public:
   
   void helper(int idx, vector<int> &nums, vector<int> currSub, vector<vector<int>> &ans){
    // there is no target or sum we have to calculate, we have to just store the evry subset we find along the path of the recursion so we store at the very first of the the recursion 

    ans.push_back(currSub);
    
    for(int i=idx;i<nums.size();i++){// for evry element we will do the recursion and explore all the possiblites
        currSub.push_back(nums[i]);// building the subest 
        // calling for the next elements

        helper(i+1,nums,currSub,ans);
        currSub.pop_back();// while back track
    }
   }
   
   
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currSub;

        helper(0,nums,currSub,ans);
        return ans;
    }
};