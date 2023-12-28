// 992. Subarrays with K Different Integers

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int x = atMostK(nums, k);
        int y = atMostK(nums, k-1);
        //cout<<x<<" "<<y<<endl;

        return x-y;
    }
private:
    int atMostK(vector<int> &nums, int k){
        unordered_map<int, int> mp;
        int res = 0;
        int left = 0, right = 0;

        while(right<nums.size()){
            mp[nums[right]]++;
            right++;
            
            while(left<nums.size() and mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0) mp.erase(nums[left]);
                left++;
            }

            res+=(right-left);
        }
        return res;
    }
};