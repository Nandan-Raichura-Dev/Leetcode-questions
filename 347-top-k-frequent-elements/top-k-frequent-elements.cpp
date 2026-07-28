class Solution {// intution : i want only the elements that contains of  high freq, so i can think of removing the elements which have small elements  , we will use the min heap, becz it gives us effcinet tc to access the min freq elementt
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int &num:nums){
            mpp[num]++;//storing all tthe frequency of giving array
        }

        // pusing all in the pq and defineinf it 
        priority_queue<P,vector<P>, greater<P>> pq;

        // maintin size k,i  exced pop it

        for(auto &it:mpp){
            int num=it.first;
            int freq=it.second;

            pq.push({freq,num});
            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<int> result;

        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};