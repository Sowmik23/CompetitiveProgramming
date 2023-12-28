class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        vector<int> res;
        int sum = 0;
        for(auto& i: nums) if(i%2==0)  sum+=i;

        for(auto& q: queries){
            int x = nums[q[1]];
            if(x%2==0) sum-=x;
            x+=q[0];
            nums[q[1]] = x;
            if(x%2==0) sum+=x;
            res.push_back(sum);
        }
        return res;
    }
};
