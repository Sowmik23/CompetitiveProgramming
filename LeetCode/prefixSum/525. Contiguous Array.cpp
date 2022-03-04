class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        //brute force: TLE
        //Time: O(n^2)
        //Space: O(1)
        
        // int res = 0;
        // for(int i=0;i<nums.size();i++){
        //     int zeros = 0, ones = 0;
        //     for(int j=i;j<nums.size();j++){
        //         if(nums[j]==0) zeros++;
        //         else ones++;
        //         if(zeros==ones) res = max(res, j-i+1);
        //     }
        // }
        // return res;
    
    
        ///using hashmap
        //Time: O(n)
        //Space: O(n)
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int mx = 0, cnt = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) cnt+=1;
            else cnt-=1;
            
            if(mp.find(cnt)!=mp.end()){
                mx = max(mx, i-mp[cnt]);
            }
            else {
                mp[cnt] = i;
            }
        }
        
        
        return mx;
    }
};
