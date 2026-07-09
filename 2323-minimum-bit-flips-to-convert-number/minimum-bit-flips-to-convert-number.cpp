class Solution {
public:
    int minBitFlips(int start, int goal) {
        // there is only one opreater which gives us the diffrencew betwwen the two gigits, in which we can compare that, how many flips are required so we will use the XOR opreater

        long ans=start^goal;// we get the entire number by doin xor , that number will consist of the all bitss fliiped to make the start to the goal

        int count=0;
        while(ans!=0){
            if(ans%2==1){
                count++;
            }
            ans=ans/2;

        }

        return count;

    }
};