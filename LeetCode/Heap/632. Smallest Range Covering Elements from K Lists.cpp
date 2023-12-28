// 632. Smallest Range Covering Elements from K Lists
class Solution {
    typedef vector<int>  arr;
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        //priority queue
        //Time: O(nlogm)

        int n = nums.size();
        //min priority queue
        priority_queue<arr, vector<arr>, greater<arr>> pq;
        int low = -1e5-1, high = 1e5+1;
        int mx = -1e5-1, mn;

        //find min, max for first row of all column
        for(int i=0;i<n;i++){
            pq.push({nums[i][0], i, 0});
            mx = max(mx, nums[i][0]);
        }

        while(pq.size()==nums.size()){
            auto top = pq.top();
            pq.pop();

            int mn = top[0];
            int i = top[1];
            int j = top[2];
            
            if(high-low>mx-mn){
                high = mx;
                low = mn;
            }
            else if(high-low==mx-mn){
                if(low>mn) {
                    low = mn;
                    high = mx;
                }
            }
            if(j+1<nums[i].size()){
                mx = max(mx, nums[i][j+1]);
                pq.push({nums[i][j+1], i, j+1});
            }
        }
        return {low, high};
    }
};