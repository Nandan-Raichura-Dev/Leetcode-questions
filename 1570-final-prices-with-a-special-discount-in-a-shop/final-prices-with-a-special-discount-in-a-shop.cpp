class Solution {
public:
    vector<int> findNse(vector<int> &arr){
        stack<int> s;
      
        int n=arr.size();
          vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            ans[i]=!s.empty()?s.top():n;
            s.push(i);

        }

        return ans;
    }



    vector<int> finalPrices(vector<int>& prices) {
        vector<int> nse=findNse(prices);
        vector<int> ans;

        for(int i=0;i<prices.size();i++){
            if(nse[i]<prices.size()){
              int element=prices[i]-prices[nse[i]];
              ans.push_back(element);
            }else{
                ans.push_back(prices[i]);
            }
        }

        return ans;
    }
};