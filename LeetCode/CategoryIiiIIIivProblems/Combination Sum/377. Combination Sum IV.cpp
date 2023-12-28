class Solution {
public:
    //set<vector<int>> st;
    //int cnt;
    int combinationSum4(vector<int>& nums, int target) {

        //cann't be solved using backtracking as it needs to find out all permutation of a combination
        /*
        sort(nums.begin(), nums.end());

        vector<int> tmp;
        backTrack(nums, tmp, target, 0, 0);

        return cnt;
        */

        //use dp: same as coin change version
        //Time: O(n*target);
        //Space: O(n)

        //TLE: O(2^target)
        // return recursive(nums, target);

        //recursion with memoization
        //Time: O(n*target)
        //Space: O(n)  
        vector<int> memo(target+1, -1);
        return recursionWithMemo(nums, memo, target);
    }
private:
    int recursive(vector<int> &nums, int target){
        if(target==0) return 1;
        if(target<0) return 0;
        int x = 0;
        for(auto& num: nums){
            if(num<=target) x+=recursive(nums, target-num);
        }
        return x;
    }

    int recursionWithMemo(vector<int> &nums, vector<int> &memo, int target){
        if(target==0) return memo[target] = 1;
        if(target<0) return memo[target] = 0;
        if(memo[target]!=-1) return memo[target];

        memo[target] = 0;
        for(auto& num: nums){
            if(num<=target) memo[target] += recursionWithMemo(nums, memo, target-num);
        }

        return memo[target];
    }
//       void backTrack(vector<int> &nums, vector<int> &tmp, int target, int idx, int sum){

//         if(sum>target) return;
//         if(sum==target){
//             // for(auto& i: tmp) cout<<i<<" ";
//             // cout<<endl;
//             cnt++;
//             if(st.count(tmp)!=0){
//                 st.insert(tmp);
//             }
//             return;
//         }
//         for(int i=idx;i<nums.size();i++){
//             tmp.push_back(nums[i]);
//             backTrack(nums, tmp, target, i, sum+nums[i]);
//             tmp.pop_back();
//         }
//         return;
//     }
};
