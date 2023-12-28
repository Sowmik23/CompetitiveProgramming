class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        //same as subarray sum equals k
        unordered_map<int, int> mp;
        int total = 0;
        int cnt = 0;
        mp[0]=1;

        for(int i=0;i<nums.size();i++){
            total = (total+nums[i]%k+k)%k; //to ensure total belong to [0, K), we should add an extra K: a % K + K to make the mod a % K positive.
            cnt+=mp[total];
            mp[total]++;

        }
        return cnt;
    }
};
