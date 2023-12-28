// 1027. Longest Arithmetic Subsequence
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        int res = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i]-nums[j];
                if(mp.count(diff)==0) mp[diff] = vector<int>(1001, 1);

                mp[diff][i] = max(mp[diff][i], mp[diff][j]+1);
                res = max(res, mp[diff][i]);
            }
        }
        return res;
    }
};