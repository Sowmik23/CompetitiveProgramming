// 1472. Design Browser History
class BrowserHistory {
public:
    stack<string> stk;
    stack<string> helper;
    string current;

    BrowserHistory(string homepage) {
        current = homepage;
    }
    
    void visit(string url) {
        stk.push(current);
        current = url;
        helper = stack<string> (); //clear the helper
    }
    
    string back(int steps) {
        while(!stk.empty() and steps>0){
            helper.push(current);
            string top = stk.top();
            current = top;
            stk.pop();
            steps--;
        }
        return current;
    }
    
    string forward(int steps) {
        while(!helper.empty() and steps>0){
            stk.push(current);
            string top = helper.top();
            current = top;
            helper.pop();
            steps--;
        }
        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */