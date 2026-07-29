class Solution {// we want to allocate the minimmum cookeis possible to the greedy child so we can maximize the child to who we can give cokkeis
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l=0;// pointer in the g array
        int r=0;// pointer in the s vector
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        while(l<n && r<m){// the cokkies can finsihed befor the greedcy child, or vice versa
            // checking whetre to pick itnup or not 

            if(s[r]>=g[l]){
                l++;// we will ove towards next children, becz the cureent one is now satisfied
            }
            // no matter what happens we will move to next cokkies
            r++;
        }
        return l;
    }
};