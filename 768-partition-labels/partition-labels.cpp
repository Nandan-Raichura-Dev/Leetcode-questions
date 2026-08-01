class Solution {
public:
    vector<int> partitionLabels(string s) {
        // we will store the last idx for the every element, this can really help to find out the partion
        vector<int>res;
        vector<int> mpp(26,-1);
        for(int i=0;i<s.size();i++){
            mpp[s[i]-'a']=i;
        }

        //computations
        int i=0;
        while(i<s.size()){
            // last occ of curr char
            int end=mpp[s[i]-'a'];
            int j=i;
            while(j<end){
                end=max(end,mpp[s[j]-'a']);
                j++;
            }
            res.push_back(j-i+1);// len of the partition
            i=j+1;


        }

        return res;
    }
};