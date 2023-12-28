class Solution {
public:
    int longestValidParentheses(string s) {
        //-1 0 1
        //-1 0

        /*
        stack<int> stk;
        int res = 0;
        stk.push(-1);

        for(int i=0;i<s.size();i++){
            if(s[i]=='(') stk.push(i);
            else {
                stk.pop();
                if(stk.empty()) stk.push(i);
                else {
                    res = max(res, i-stk.top());
                }
            }
        }
        return res;
        */

        //stack with DP
        stack<pair<char, int>> stk;
        vector<int> nums(s.size());

        for(int i=0;i<s.size();i++){
            if(s[i]=='(') stk.push({'(', i});
            else {
                if(!stk.empty()){
                    if(stk.top().first=='('){
                        nums[i] = 1;
                        nums[stk.top().second] = 1;
                    }
                    else nums[i] = 0;
                    stk.pop();
                }
                else nums[i] = 0;
            }
        }
        //for(auto n : nums) cout<<n<<" "; //now nums is a 010111 like array
        //now we will find max 111 as subsequence in nums and that is the answer
        int res = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) cnt++;
            else {
                res = max(res, cnt);
                cnt = 0;
            }
        }
        res = max(res, cnt);

        return res;
    }
};


class Solution {
public:
    int longestValidParentheses(string s) {

        int res = 0;

        stack<int> stk;
        stk.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                stk.push(i);
            }
            else {
                stk.pop();
                if(stk.empty()){
                    stk.push(i);
                }
                else {
                    res = max(res, i-stk.top());
                }
            }
        }

        return res;
    }
};
