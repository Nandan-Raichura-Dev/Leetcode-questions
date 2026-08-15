class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        if(n==0){
            return 0;
        }
        int currSum=0;

        int currFloor=0;

      

        for(int i=0;i<requests.size();i++){
            currSum+=abs(requests[i]-currFloor);
            currFloor=requests[i];
        }

        return currSum;
        
    }
};