class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        
        int n = nums.size();
        vector<int> res(n);
        
        n = n-1;
        int left = 0, right = nums.size()-1;
        
        while(left<=right){
            if(nums[left]*nums[left] < nums[right]*nums[right]){
                res[n] = nums[right]*nums[right];
                right--;
            }
            else {
                res[n] = nums[left]*nums[left];
                left++;
            }
            n--;
        }
        
        return res;
    }
};
