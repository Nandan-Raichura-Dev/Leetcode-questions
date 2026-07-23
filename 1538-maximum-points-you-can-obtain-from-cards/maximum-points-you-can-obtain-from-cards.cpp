class Solution {// we will take the leftsum and right sum with thier appropriate window so we will chooose the accordingly
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int rightSum=0;
        int leftSum=0;

        int maxSum=0;

        for(int i=0;i<k;i++){// first weare trying all the elements from the left
        leftSum+=cardPoints[i];
        }
        maxSum=leftSum;

        // now we explore thr diff options

        // fisrt we will minum one element form the left, two then 3 nd its goes on, but to compansate we will also add the element form the right

        int rightIdx=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            leftSum=leftSum-cardPoints[i];
            rightSum=rightSum+cardPoints[rightIdx];
            maxSum=max(maxSum,leftSum+rightSum);
            rightIdx--;
        }

        return maxSum;
    }
};