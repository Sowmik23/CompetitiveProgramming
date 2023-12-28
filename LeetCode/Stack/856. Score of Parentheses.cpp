class Solution {
public:
    int scoreOfParentheses(string s) {


        //Time: O(n)
        //Space: O(1)

        int score = 0;
        int depth = 0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='(') depth++;
            else depth--;

            if(s[i]==')' and s[i-1]=='(') score+= pow(2, depth);
        }
        return score;
        */

        //Time+Space: O(n)
        stack<int> stk;
        stk.push(0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') stk.push(0);
            else {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();

                stk.push(y+max(2*x, 1));
            }
        }
        return stk.top();
    }
};


class Solution {
public:
    int scoreOfParentheses(string s) {

        //Time: O(n)
        //Space: O(n)

        stack<int> stk;
        stk.push(0);

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                stk.push(0);
            }
            else {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();

                stk.push(y+max(2*x, 1));
            }
        }

        return stk.top();
    }
};
