class Solution {// here in brut eforce we will use nse and pse, becz we weant to keep track of the bar thatr are the equal or the bigger then the size so we will make our range of the rectangle uintil we not found the nse or pse, so we can stop there
public:
        // to find the next smaller elemeent
    vector<int> findNse(vector<int> &arr){
        int n=arr.size();
        vector<int> ans(n);

        stack<int> s;

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            ans[i]=!s.empty()?s.top():n;
            s.push(i);
        }
        return ans;
    }

    vector<int> findPse(vector<int> &arr){
      
        int n=arr.size();
          vector<int> ans(n);

        stack<int> s;

        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            ans[i]=!s.empty()?s.top():-1;
            s.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextSmall=findNse(heights);
        vector<int> prevSmall=findPse(heights);

        int n=heights.size();

        long long maxi=0;

        for(int i=0;i<n;i++){
            int left=prevSmall[i];
            int right=nextSmall[i];

            long long val=(long long)(right-left-1)*heights[i];// area of the rectangle 

            maxi=max(maxi,val);

        }

        return maxi;
    }
};