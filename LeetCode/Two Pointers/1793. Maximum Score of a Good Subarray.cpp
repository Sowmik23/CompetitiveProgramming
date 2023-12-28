// 1793. Maximum Score of a Good Subarray

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {

        //Using Monotonic Stack
        //Time: O(n)
        /*
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        vector<int> stk;

        for(int i=n-1;i>=0;i--){
            while(!stk.empty() and nums[stk.back()]>nums[i]) {
                left[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }   

        //clear and re-use the stack
        stk.clear();
        for(int i=0;i<n;i++){
            while(!stk.empty() and nums[stk.back()]>nums[i]){
                right[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }

        int res = 0;
        for(int i=0;i<n;i++){
            if(left[i]<k and right[i]>k){
                res = max(res, nums[i]*(right[i]-left[i]-1));
            }
        }
        return res;

        */

        //Greedy
        //Time: O(n)
        int n = nums.size();
        int res = nums[k];
        int currMin = nums[k];
        int left = k;
        int right = k;
        while(left>0 or right<n-1){
            if( (left>0 ? nums[left-1] : 0) > (right<n-1 ? nums[right+1] : 0) ){
                left--;
                currMin = min(currMin, nums[left]);
            }
            else {
                right++;
                currMin = min(currMin, nums[right]);
            }
            res = max(res, currMin*(right-left+1));
        }
        return res;
    }
};