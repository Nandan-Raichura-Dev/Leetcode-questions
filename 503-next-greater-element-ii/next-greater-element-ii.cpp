class Solution {// we will visualize the hypothetical array, we will double the array so we dont have to search circularly and we will just play with indexes.. we willuse monotonic stack concept
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n);

        stack<int> s;

        for(int i=n*2-1;i>=0;i--){
            while(!s.empty() && nums[i%n]>=s.top()){
                s.pop();
                }

                // we have removed the small elements then the current one in the array
                if(i<n){// for the orginal indexes only.. we will find out the nge
                    arr[i]=s.empty()?-1:s.top();
                }

                // we will add the current element form the nums to the stack

                s.push(nums[i%n]);

        }

        return arr;
        
    }
};