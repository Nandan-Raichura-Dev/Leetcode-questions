class Solution {// we will only find the the max gap bettewn the two worker, our task is to place them as fasr as possbile so we can then get the max gap, 
public:
    int maximumGap(string skill, string station) {
        int n=skill.size();
        int m=station.size();
        if(n==1){
            return 0;
        }
        vector<int> left(n) , right(n);

        // leftMost greedy match ,finding the earliest possbile match for the worker i

        int p=0;
        for(int i=0;i<n;i++){
            while(station[p]!=skill[i]) p++;
            left[i]=p;
            p++;
        }

        // rightMost greedy match,finding the rightMost possible match or we can say latest possible station index for the ith worker

        int q=m-1;
        for(int i=n-1;i>=0;i--){
            while(station[q]!=skill[i]) q--;
            right[i]=q;
            q--;
        }

       // for each consecutive pair (i-1,i),
        // the largest gap achievable is R[i]-L[i-1]
        int ans=0;

        for(int i=1;i<n;i++){
            ans=max(ans,right[i]-left[i-1]);
        }
        
        return ans;

    }
};