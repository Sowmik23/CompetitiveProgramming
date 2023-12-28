// 6328. Find the Substring With Maximum Cost

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        
        unordered_map<char, int> mp;
        for(int i=0;i<chars.size();i++) mp[chars[i]]=i;
        
        vector<int> nums;
        for(auto& ch: s){
            if(mp.find(ch)!=mp.end()){
                nums.push_back(vals[mp[ch]]);
            }
            else nums.push_back(ch-'a'+1);
        }
        
        //for(auto& n: nums) cout<<n<<" ";
        
        //now find maximum subarray sum: kadane's algorithm
        int sum = 0;
        int maxSum = INT_MIN;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(maxSum<sum){
                maxSum = sum;
            }
           if(sum<0) sum = 0;
        }

        if(maxSum<0) return 0;
        return maxSum;
    }
};