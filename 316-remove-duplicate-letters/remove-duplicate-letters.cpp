class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIdx(26,0);

        for(int i=0;i<s.length();i++){
            lastIdx[s[i]-'a']=i;
        }
        vector<bool> seen(26,false);

        stack<char> st;


        for(int i=0;i<s.size();i++){
            if(seen[s[i]-'a']){// if it is already there ihn the stack we will just continue
                continue;
            }
            while(!st.empty() && st.top()>s[i] && i<lastIdx[st.top()-'a']){// lastIdx checks whethre the number is ocurring in the futrure
              
                // making ihe poped char unseen
                seen[st.top()-'a']=false;
                st.pop();
            }
            st.push(s[i]);
            seen[s[i]-'a']=true;

            // now we have all unique element
        }

        string ans="";

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};