class Solution {// here we will use the intrval to add oanther element, so we get minimmum time for the demanded input

public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;// by defualt it is the maxheap
        vector<int> mpp(26,0);
        int time=0;



        for(int i=0;i<tasks.size();i++){// we will be storing  the freq for all the char
            mpp[tasks[i]-'A']++;
        }

        for(int i=0;i<mpp.size();i++){// we willl push it into the map,this will make the the char with higher freq at the top, becz it is the maxheap
            if(mpp[i]>0){
                pq.push(mpp[i]);
            }
        }

        while(!pq.empty()){
                
                vector<int> temp;

                for(int i=1;i<=n+1;i++){// we will run the loop to take the n+1 eleemnts from the pq, so we can process it

                if(!pq.empty()){
                    int freq=pq.top();
                    pq.pop();
                    freq--;// we have placed it so we will minus the freq
                    temp.push_back(freq);
                }
                }

                for(int &f:temp){
                    if(f>0){
                        pq.push(f);
                    }
                }

                if(pq.empty()){
                    time+=temp.size();// this will triger when we we have which is diff and they appear one time only so will add it without considering the idle 
                }else{
                    time=time+(n+1);// it is fixed that each element will take the n+1 time 
                }

                
        }
            return time;

    }
};