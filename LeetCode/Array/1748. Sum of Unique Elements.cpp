class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        
        unordered_map<int, int> ump;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            ump[nums[i]]++;
        }
        for(auto i: ump){
            if(i.second==1){
                sum+=i.first;
            }
        }
        return sum;
    }
};
