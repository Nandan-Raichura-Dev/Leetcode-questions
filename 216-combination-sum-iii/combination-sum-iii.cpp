class Solution {
public:
    void helper(int idx,int target,int k,vector<vector<int>> &ans,vector<int> &ds){
        // if the target =0 and the k is also 0 it means elements are satisfiying the all requiremnet to be in the ans

        if(target==0 && k==0){// succes condtion and base case
            ans.push_back(ds);
            return;// just backtrack
        }

        if(k==0 || target<0){// failure codition,if the k is equal to the 3 and the sum is not 0 then we will return (or we overshoot the target)
            return;// backtrack
        }

        // if these cases dont hit we have to still pick the element

        for(int i=idx;i<=9;i++){
            if(i>target){
                break;// if the current num is greater and cant be in the target , we can take other elements furthere from thiss
                
            }
            // otherwise we will pick
            ds.push_back(i);
            // for furthere elementss and the recursion 
            
             helper(i+1,target-i,k-1,ans,ds);// picked and skiped the i (current) so pick the next element from i
             ds.pop_back();// so we can use thhis for furtthere recursion
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;

        helper(1,n,k,ans,ds);
        return ans;
    }
};