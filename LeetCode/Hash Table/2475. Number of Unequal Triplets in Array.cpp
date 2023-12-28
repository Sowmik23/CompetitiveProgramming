// 2475. Number of Unequal Triplets in Array
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        int pairs = 0;
        int triplets = 0;

        /* pairs_with_a = count[A[i]] * (i - count[A[i]]) pairs contains A[i]
           so pairs_without_a = pairs - pairs_with_a
           and A[i] can combine new_triplets_with_a = pairs_without_a
        */
        
        for(int i=0;i<nums.size();i++){
            triplets +=pairs - mp[nums[i]]*(i-mp[nums[i]]);
            pairs += (i-mp[nums[i]]);
            mp[nums[i]]++;
        }
        return triplets;
    }
};