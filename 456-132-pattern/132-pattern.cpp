class Solution {// here we will store the largest element in the stack , so intution is like , i have to scan right to left, and checking three consicutive
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int thirdElement=INT_MIN;// thirdElement= second smallest element, ans if the arr[i] gets smaller then the seond smallest we will return true

        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<thirdElement){
                return true;
            }
            while(!st.empty() && st.top()<nums[i]){
                thirdElement=st.top();// so here we have found the greater element  then the top was storing, so will tranfer the top to the third element, (second largest) 
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};