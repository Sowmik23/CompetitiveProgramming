class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        if(nums.size()<3)  return 0;
        vector<unordered_map<long, long>> mp(nums.size()+1);

        int res = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                long diff = (long) nums[i]-nums[j];

                res+=mp[j][diff];
                mp[i][diff]+=mp[j][diff];
                mp[i][diff]++;
            }
        }
        return res;
    }
};




    
