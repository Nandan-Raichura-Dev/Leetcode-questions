class Solution {
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

        // if the element is still left over, becz these element do not have nse

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


    int maximalRectangle(vector<vector<char>>& matrix) {
           int n=matrix.size();
           int m=matrix[0].size();

           vector<vector<int>> prefixSum(n,vector<int>(m,0));



           for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=matrix[i][j]-'0';
                if(matrix[i][j]=='0'){
                    sum=0;
                }
                prefixSum[i][j]=sum;
            }
           }

           // calling the largestrectangle area for the each row in the prefixSum matrix
            int area=0;
           for(int i=0;i<n;i++){
             area= max(area,largestRectangleArea(prefixSum[i]));// passing the row for the matrix
            
           }

           return area;
    }
};