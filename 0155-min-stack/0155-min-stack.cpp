class MinStack {
public:
    long long int min=INT_MAX;
    stack<long long int> stk;
    MinStack() {
        
    }
    
    void push(long long int val) {
        if(stk.empty()) {
            min=val;
            stk.push(val);
        }   
        else {
            if(val>min) stk.push(val);
            else {
                stk.push(2*val-min);
                min=val;
            }
        }
    }
    
    void pop() {
        if(stk.empty()) return;
        long long int x=stk.top();
        stk.pop();
        if(x<min) min=2*min-x;
    }
    
    int top() {
        if(stk.empty()) return 0;
        long long int x=stk.top();
        if(min<x) return x;
        else return min;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */