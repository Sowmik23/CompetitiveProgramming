class Solution {
public:
    int trap(vector<int>& height) {
        //monotonic stack
        /*stack<int> stk;
        int res=0;

        for(int i=0;i<height.size();i++){
            int current = height[i];
            while(!stk.empty() and current>height[stk.top()]){
                int top =stk.top();
                stk.pop();
                if(stk.empty()) break;

                int distance = i-stk.top()-1;
                int h = min(current, height[stk.top()])-height[top];
                res+=h*distance;
            }
            stk.push(i);
        }
        return res;
        */


        //dp
        int res=0;
        int n = height.size();
        vector<int> leftMax(n), rightMax(n);

        leftMax[0] = height[0];
        for(int i=1;i<n;i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        rightMax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        for(int i=0;i<n;i++){
            res+=min(leftMax[i], rightMax[i])-height[i];
        }
        return res;

        //two pointer

    }
};
