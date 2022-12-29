class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

//         int X = INT_MAX, Y = INT_MAX;

//         for(int i=0;i<nums.size();i++){

//             if(nums[i]<=X)  X = nums[i];
//             else if(nums[i]<=Y) Y = nums[i];
//             else return true;
//         }

//         return false;

        //apprroache-02: same but can use this for k nums comparison
        int k = 3;
        vector<int> sequence(k-1, INT_MAX);
        for(auto& i: nums){
            auto p = lower_bound(sequence.begin(), sequence.end(), i);
            if(p==sequence.end()) return true;
           *p = i;
        }
        return false;
    }
};
