class Solution {
public:
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


    
    void helper(int idx,string &digits,string &curr,vector<string> &ans){

            if(idx==digits.size()){// base case when we also picked up the element from the another number, eaxample if number is 23, if we have picked up a and then d , then we hit the base case becz our idx will be == size of "23"

                ans.push_back(curr);
                return;
            }

            // taking out the string for the current level 

            string ch=mapping[digits[idx]-'0'];// taking out the string for the letter for example here abc
            
            for(char c:ch){// taking out the single letter fpr example a , b, c

            curr.push_back(c);
            // for the combination from the next digitfor example looking for the d from the number 2nd

            helper(idx+1,digits,curr,ans);
            curr.pop_back();// backtrack to remove the last addes element when we return 
            }

    }
    vector<string> letterCombinations(string digits) {
        string curr;
        vector<string> ans;

        helper(0,digits,curr,ans);
        return ans;
    }
};