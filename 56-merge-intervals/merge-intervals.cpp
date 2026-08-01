class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
       int n=arr.size();

       vector<vector<int>> ans;

       for(int i=0;i<n;i++){
        if(ans.empty() ||arr[i][0]>ans.back()[1] ){// checking if it is first element or the new section / interval is starting
            ans.push_back(arr[i]);
        }
        else{

            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
       } 
       return ans;
    }
};