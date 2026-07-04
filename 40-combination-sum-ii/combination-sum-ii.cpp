class Solution {// in brute force solution we have just modify the combination 1 approach and the code, just i+1, in the not picking section of the code, and we will use the hasset to store only unique elements, below code is optimized becz we are not using any space
public:
    void findCombo(int idx,vector<int> &arr,int target,vector<int>ds,vector<vector<int>> &ans){
        if(target==0){// base case when we get our sum
            ans.push_back(ds);
            return;
        }

        //  if the base case didnt hit we will conitnue the recursion

        // we have to explore the evry option from the particular idx to the last of the array , so for the each element we will explore the whole array(wethere this element can be my current required element ??) 

        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1]){// if the element is the same as we pick earlier and it is not the first element we are chossing, means when we are exploreing the all elemets in the first level so  we skip tthat, so i>idx means it is not first time .
            continue;

            }
            if(arr[i]>target){
                break;
            }
            // here we can pickit if the above condtion is nott fullfiled

            ds.push_back(arr[i]);
            // we will call it for the next combination or furthere tasks
            findCombo(i+1,arr,target-arr[i],ds,ans);
            
            ds.pop_back();// while backtraking 
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;

        findCombo(0,candidates,target,ds,ans);
        return ans;
    }
};