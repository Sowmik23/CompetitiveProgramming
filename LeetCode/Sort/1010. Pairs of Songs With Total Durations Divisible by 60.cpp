class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        //we can also do it using hashtable
        
        // Another approach is bucket sort
        // Time: O(n)
        // Space: O(n)
        
        int cnt = 0;
        vector<int> bucket(60);
        for(int i=0;i<time.size();i++){
            int val = time[i]%60;
            
            cnt+=bucket[(60-val)%60];
            bucket[val]++;
        }
        
        return cnt;
    }
};
