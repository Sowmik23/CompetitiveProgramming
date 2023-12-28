// 2616. Minimize the Maximum Difference of Pairs
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = nums[n-1]-nums[0];

        while(left<right){
            int mid = left+(right-left)/2;
            if(findPairs(nums, mid)>=p){
                right = mid;
            }
            else left = mid+1;
        }
        return left;
    }
private:
    int findPairs(vector<int> &nums, int diff){
        int idx = 0;
        int cnt = 0;
        while(idx+1<nums.size()){
            if(nums[idx+1]-nums[idx]<=diff) {
                cnt++;
                idx++;
            }
            idx++;
        }
        return cnt;
    }
};