class FreqStack {
public:
    vector<stack<int>*> stk;
    unordered_map<int, int> freq;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        
        freq[val]++;
        int k = freq[val]-1;
        if(k<stk.size()) stk[k]->push(val);
        else{
            stack<int> *st = new stack<int>;
            st->push(val);
            stk.push_back(st);
        }
    }
    
    int pop() {
        int val = stk.back()->top();
        stk.back()->pop();
       if(stk.back()->empty()) stk.pop_back();
        freq[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
