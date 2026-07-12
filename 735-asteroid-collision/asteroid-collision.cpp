class Solution {// positive element = right direction, negative = left , both collaide
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> ls;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>0){// it means it consistt of the positive element 
                ls.push_back(arr[i]);

            }else{// negative element

                while(!ls.empty() && ls.back()>0 && ls.back()<abs(arr[i])){// here we wrote the ls.back()> 0 becz we wwant to pop out the element until it is positive and at the samew time it should be smller than abs value of the arr[i]

                    ls.pop_back();
                }
                // if any element is left or any other posssiblity
                if(!ls.empty() && abs(arr[i])==ls.back()){// if the element of the same size
                    ls.pop_back();
                }else if(ls.empty() || ls.back()<0){// here the negative element can be added
                    ls.push_back(arr[i]);
                }
            }
        }

        return ls;
    }
};