class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        //Time: O(n), Memory: O(n)
       // countingSort(nums);
        
        //Time: O(n), Space: O(1): One pass in-place
        int j = nums.size()-1;
        int k = 0;
        for(int i=0;i<=j;i++){
            if(nums[i]==0){
                swap(nums[i], nums[k]);
                k++;
            }
            else if(nums[i]==2){
                swap(nums[i], nums[j]);
                j--;
                i--;//here you need to decrease i as you need to consider this position's number also
            }
        }
    }
    
private:
    void countingSort(vector<int> &nums){
        int mn = INT_MAX;
        int mx = INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        
        vector<int> cnt(mx-mn+1, 0);
        
        for(auto& i: nums){
            cnt[i-mn]++;
        }
        
        for(int i=1;i<cnt.size();i++){
            cnt[i] += cnt[i-1];
        }
        
        vector<int> sortedNums(nums.size());
        
        for(int i=nums.size()-1;i>=0;i--){
            sortedNums[cnt[nums[i]-mn]-1] = nums[i];
            cnt[nums[i]-mn]--;
        }
        
        for(int i=0;i<nums.size();i++){
            nums[i] = sortedNums[i];
        }
    }
};
