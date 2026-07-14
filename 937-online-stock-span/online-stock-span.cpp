class StockSpanner {
public:

       stack<pair<int,int>> s;
       int idx=-1;


    StockSpanner() {
       
       idx=-1;
      s = stack<pair<int, int>>();

    }
    
    int next(int price) {
        idx=idx+1;
        while(!s.empty() && s.top().first<=price){
            s.pop();
        }
        int temp=!s.empty()?s.top().second:-1;
        int ans=idx-temp;

        s.push({price,idx});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */