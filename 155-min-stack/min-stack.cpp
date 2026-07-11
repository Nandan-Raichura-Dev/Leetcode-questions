class MinStack {
public:
    stack<long long> s;
    long long min=INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        if(s.empty()){
            min=value;
            s.push(value);
        }else{// we will not store the actual value of the element in the stack becz if we do that, and change the minium , if the pop opreation have been done , then we have told to take out the new min , we will not able to get back to the old min, we will have the minium, of the element we have poped

            if(value>min){
                s.push(value);// min is not needed to change so we push the element without any changes
            }else{
                s.push(2LL*value-min);

                min=value;
            }
        }
    }
    
    void pop() {
        if(s.empty()){
            return;
        }
        long long n=s.top();
        if(n<min){// if the n is modeified value, it will be lesser then the min;tjen we have to back to the prev min

        min=2*min-n;

        }
        s.pop();
    }
    
    int top() {
        if(s.empty()){
            return -1;;
        }

        long long n=s.top();
        if(min<n){// in this case the n is not modified value, so we have to return the top
            return n;
        }else{
            return min;// in this case min will be our top , as well as the min value of the entire stack

        }
    }
    
    int getMin() {
       return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */