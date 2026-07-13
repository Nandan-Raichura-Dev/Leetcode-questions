class Solution {
public:

    
    long long subArrayRanges(vector<int>& nums) {
        // Size of array

        int n = nums.size();
        
        // To store the sum
        long long sum = 0;
        
        // Traverse on the array
        for(int i=0; i < n; i++) {
            
            // To store the smallest value of subarray
            int smallest = nums[i];
            
            // To store the largest value of subarray
            int largest = nums[i];
            
            /* Nested loop to get all 
            subarrays starting from index i */
            for(int j=i; j < n; j++) {
                
                // Update the smallest value
                smallest = min(smallest, nums[j]);
                
                // Update the largest value
                largest = max(largest, nums[j]);
                
                // Update the sum
                sum += (largest - smallest);
            }
        }
        
        // Return the computed sum
        return sum;
    }
};