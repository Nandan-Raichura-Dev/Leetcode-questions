class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();

        // revrse the connection, make the child list where children[p] = list of nodes whose parent is p

        vector<vector<int>> children(n);

        for(int i=1;i<n;i++){
            children[parent[i]].push_back(i);// who is my chhild
        }

       // bfs from root to get depth

        vector<int> depth(n);

        depth[0]=1;
        int h=1;

        queue<int> q;

        q.push(0);// pushing the first root

        while(!q.empty()){

                int node=q.front();
                q.pop();
                // processing the child of this node, we will use the list we had bulit eariler

                for(int child:children[node]){
                    depth[child]=depth[node]+1;// we know the child node have one more then depth pf the parent node
                     h=max(h,depth[child]);
                q.push(child);// procesing the child also becz they might have an child
                }

               
        }


        long long total = 0;
        for (int i = 0; i < n; i++)
            total += (long long)nums[i] * (h - depth[i] + 1);

        return total;

    }
};