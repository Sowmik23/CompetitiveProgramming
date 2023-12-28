// 41. First Missing Positive
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        //Time: O(n), Space: O(n)
        /*
        unordered_map<int, bool> mp;
        for(auto n: nums) mp[n] = true;
        int i = 1;
        while(true){
            if(mp[i]==false) return i;
            i++;
        }
        return -1;
        */

        //Time: O(n), Space: O(1)
        int n = nums.size();
        for(int i=0;i<n;i++){
            int curr = nums[i];
            while(curr>0 and curr<=n and curr!=nums[curr-1]){
                swap(curr, nums[curr-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }

        return n+1;
    }
};