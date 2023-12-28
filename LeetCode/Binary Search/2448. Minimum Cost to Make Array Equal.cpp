// 2448. Minimum Cost to Make Array Equal
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        // Using sorting and prefix sum
        // Time: O(nlogn)
        /*
        int n = nums.size();
        vector<vector<int>> numsAndCost(n, vector<int> (2));
        vector<long> prefixCost(n);

        for(int i=0;i<n;i++){
            numsAndCost[i][0] = nums[i];
            numsAndCost[i][1] = cost[i];
         }

         sort(numsAndCost.begin(), numsAndCost.end(), [](auto& a, auto& b){
             return a[0]<b[0];
         });

         prefixCost[0] = numsAndCost[0][1];
         for(int i=1;i<n;i++){
             prefixCost[i] = prefixCost[i-1] + numsAndCost[i][1];
         }

         long totalCost = 0;
         for(int i=1;i<n;i++){
             totalCost += (long) ((long)numsAndCost[i][1]*(numsAndCost[i][0]-numsAndCost[0][0]));
         }

         long res = totalCost;
         for(int i=1;i<n;i++){
             int gap = numsAndCost[i][0] - numsAndCost[i-1][0];
             totalCost +=(long) prefixCost[i-1]*gap;
             totalCost -= (long) (prefixCost[n-1]-prefixCost[i-1])*gap;
             res = min(res, totalCost);
         }

        return res;
        */


        //Using Binary Search
        // Time: O(nlogk)

        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        long long res = getCost(nums, cost, nums[0]);

        //prank: binary search in unsorted array :)
        while(left<right){
            int mid = (left+right)/2;
            long long cost1 = getCost(nums, cost, mid);
            long long cost2 = getCost(nums, cost, mid+1);
            res = min(cost1, cost2);
            if(cost1>cost2) left = mid+1;
            else right = mid;
        }
        return res;
    }
private:
    long long getCost(vector<int> &nums, vector<int> &cost, int base){
        long long res = 0;
        for(int i=0;i<nums.size();i++){
            res+= (long long) abs(nums[i]-base)*cost[i];
        }
        return res;
    }
};
