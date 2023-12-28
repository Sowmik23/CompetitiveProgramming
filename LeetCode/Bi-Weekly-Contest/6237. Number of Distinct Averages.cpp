class Solution {
public:
    int distinctAverages(vector<int>& nums) {

        priority_queue<int> mxPq;
        priority_queue<int, vector<int> , greater<int>> mnPq;

        for(auto& num: nums){
            mxPq.push(num);
            mnPq.push(num);
        }

        set<double> st;

        int cnt = 0;
        while(cnt<nums.size() and !mxPq.empty() and !mnPq.empty()){
            double avg = (mxPq.top() + mnPq.top())/2.0;
            mxPq.pop();
            mnPq.pop();
            cnt++;
            //cout<<avg<<endl;

            st.insert(avg);
        }
        return st.size();
    }
};
