class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        
        unordered_map<int, int> mp;
        
        int i = 0;
        while(i<nums.size()){
            //while(i<nums.size()-1 and nums[i]==key) i++;
            if(nums[i]==key){
                i++;
                mp[nums[i]]++;  
            } 
            i++;
        }
        
        int res;
        int cnt = INT_MIN;
        bool flag = false;
        
        for(auto& n: nums){
            if(n==key) flag=true;
            if(flag==true and mp[n]>cnt) {
                cnt = mp[n];
                res = n;
            }
        }
        
        return res;
    }
};
