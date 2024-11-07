class StockSpanner {
public:
    stack<pair<int,int>> stk;
    int ind=-1;
    void clearStack(stack<pair<int,int>>& stk) {
        while(!stk.empty())
            stk.pop();
    }
    StockSpanner() {
        ind=-1;
        clearStack(stk);
    }
    
    int next(int price) {
        ind=ind+1;
        while(!stk.empty() && stk.top().first<=price)
            stk.pop();
        int ans=ind-((stk.empty()?-1:stk.top().second));
        stk.push({price,ind});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */