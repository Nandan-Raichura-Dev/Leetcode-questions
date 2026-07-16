class Solution {
public:
    vector<int> findNge(vector<int> &arr){
        int n=arr.size();
        vector<int> nge(n,0);

        stack<int> s;

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]<=arr[i]){
                s.pop();
            }
            if(!s.empty()){
                nge[i]=s.top();
            }
            s.push(i);
        }
        return nge;
    }

    vector<int> dailyTemperatures(vector<int>& arr) {
        vector<int> nge=findNge(arr);
        int n=arr.size();
        vector<int> ans(n);

        for(int i=0;i<arr.size();i++){
            if(nge[i]!=0){
                ans[i]=nge[i]-i;
            }
        }

        return ans;
    }
};