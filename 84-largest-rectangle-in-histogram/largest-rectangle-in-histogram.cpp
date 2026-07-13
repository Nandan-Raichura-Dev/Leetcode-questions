class Solution {// brute by taking out nse and pse and arr[i]*nse-pse
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n=heights.size();

        long long maxi=0;
// only caluculating the pse , and while poping out the element we will process that and take out the area for that
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>heights[i]){
                    long element=heights[s.top()];// element to be processed

                    s.pop();
                    int nse=i;//current element , in which are standing at 

                    int pse=!s.empty()?s.top():-1;
            
                    long long val = (long long)element * (nse - pse - 1);

                     maxi=max(maxi,val);// we are checking when we are coming back for poping out the element , becz at that time we really know that we have the nse, becz we have trvalled further



            }
            s.push(i);
        }

        // if the element is still left over, beca these element do not have nse

        while(!s.empty()){
            int element=heights[s.top()];

            s.pop();

            int nse=n;

            int pse=!s.empty()?s.top():-1;
            
           long long val = (long long)element * (nse - pse - 1);

            maxi=max(maxi,val);// we are checking when we are coming back for poping out the element , becz at that time we really know that we have the nse, becz we have trvalled further



        }

        return maxi;
    }
};