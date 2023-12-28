// 862. Shortest Subarray with Sum at Least K
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        //TODO:
        //Note: num elements can be negative
        //Need to solve using monotonic queue/dequeue

        int n = nums.size();
        int res = n+1;

        deque<long> dq;
        vector<long> prefixSum(n);

        prefixSum[0] = nums[0];
        for(int i=0;i<n;i++){
            if(i>0) prefixSum[i]+=prefixSum[i-1]+nums[i];
            if(prefixSum[i]>=k) res = min(res, i+1);
            while(dq.size()>0 and prefixSum[i]-prefixSum[dq.front()]>=k){
                res = min(res, i-dq.front());
                dq.pop_front();
            }
            while(dq.size()>0 and prefixSum[i]<=prefixSum[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return res<=n ? res : -1;
    }
private:
    int min(int a, int b){ return a<b ? a : b; }
};