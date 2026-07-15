class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int> s;
        vector<char> ans;

       for(string& ch:op){
        // there will be the diffrent condtion for the each opreation 

        if(isdigit(ch[0])||ch[0]=='-'){
            s.push(stoi(ch));
        }else if(ch=="C"){
            s.pop();
        }else if(ch=="D"){
            int element=s.top()*2;
            s.push(element);
            
        }else if(ch=="+"){
            int element1=s.top();
            s.pop();
            int element2=s.top();
            int element3=element1+element2;
            s.push(element1);
            s.push(element3);
        }
       }

        int sum=0;
       while(!s.empty()){
        int element=s.top();

        s.pop();
        sum+=element;
        

       }

       return sum;
    }
};