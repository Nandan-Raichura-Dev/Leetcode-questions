class Solution {
public:

   void helper(vector<string> &vec,int n,int oc,int cc, string s){
        if(oc==n && cc==n){// base case.if the opening bracket ad closing bracket are equal in amount
            vec.push_back(s);
            return;
        }

        if(oc<n){
            helper(vec,n,oc+1,cc,s+"(");
        }

        if(cc<oc){
            helper(vec,n,oc,cc+1,s+")");// while backtraking it checks and execute
        }
    }

    vector<string> generateParenthesis(int n) {
        // we will explore the all two cases for evry  bracket, in which if oc < n (opening breakets can be added) and if cc < oc(it means more closing can be added becz there is opening cbrekets that need to closed)

        vector<string> vec;
        int oc=0,cc=0;

        helper(vec,n,oc,cc,"");
        return vec;
    }
};