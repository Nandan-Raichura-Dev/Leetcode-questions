class Solution {
public:
    void reverseString(vector<char>& s) {
        int j=s.size()-1;
        for(int i=0;i<s.size();i++){
            if(i>=j){
                break;// if very at the begining pointer cross each other
            }
            char ch=s[i];
            s[i]=s[j];
            s[j]=ch;
            j--;

            if(i==j){
                break;
            }
        }
    }
};