// 1441. Build an Array With Stack Operations

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> res;
        stack<int> stk;

        int stream = 1;
        int prev = -1;
        for(auto& t: target){
            if(stream==t){
                prev = stream;
                stk.push(stream);
                res.push_back("Push");
                stream++;
            }
            else if(stream<t){
                while(stream<t){
                    stk.push(stream);
                    res.push_back("Push");
                    while(!stk.empty() and stk.top()!=prev){
                        stk.pop();
                        res.push_back("Pop");
                    }
                    stream++;
                }
                stk.push(stream);
                res.push_back("Push");
                prev = stream;
                stream++;
            }
        }
        return res;
    }
};