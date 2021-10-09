class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        ///Solving approach: Dequeue
        //Time: O(n-k);
        
        vector<int> res;
        deque<int> dq;
        
        for(int i=0;i<nums.size();i++){
            
            //as window moving on so left part of window is poped....
            if(dq.front()==i-k) dq.pop_front();
            
            //just updating the deque front element to max and so deleting back element and updating to max
            while(!dq.empty() and nums[i]>nums[dq.back()]) dq.pop_back();
            
            //keep adding index into dq
            dq.push_back(i);
            
            //store each windows max value in res 
            if(i-k+1>=0) res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};
