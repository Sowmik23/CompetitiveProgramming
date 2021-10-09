class MinStack {
public:
    /** initialize your data structure here. */
    ///Approach-01: Using stack
    /*
    stack<pair<int, int>> stk;
    
    MinStack() {
        stk = stack<pair<int, int>> ();    
    }
    
    void push(int val) {
        int mn;
        if(stk.empty()) mn = val;
        else mn = min(val, stk.top().second);
        
        stk.push(make_pair(val, mn));
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
    */
    
    ///Another approach-02: Using vector;
    vector<pair<int, int>> minStack;
    
    MinStack(){
        minStack = vector<pair<int, int>> ();
    }
    
    void push(int val){
        int mn;
        if(minStack.empty()) mn = val;
        else {
            mn = min(val, minStack.back().second);
        }
        minStack.push_back(make_pair(val, mn));
    }
    
    void pop(){
        minStack.pop_back();
    }
    int top(){
        return minStack.back().first;
    }
    
    int getMin(){
        return minStack.back().second;
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
