class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
       //bad decision of using sliding window, as array contains negative value also
        
        //Brute force
        // Time: O(n^2) :TLE
        
        /*
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            for(int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                if(k==sum) cnt++;
            }       
        }
        
        return cnt;
        */
        
        //so we use hash map
        //Time: O(n)
        //Space: O(n)
        
        //Concept: prefixSum 
        
        unordered_map<int, int> mp;
        
        int cnt = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
            if(sum==k) cnt++;
            if(mp.count(sum-k)){
                cnt+=mp[sum-k];
            }
            
            //store the prefix sum in hashmap
            mp[sum]++;
        }
        
        return cnt;
    }
};

