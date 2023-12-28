// 2094. Finding 3-Digit Even Numbers
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        
        int n = digits.size();
        vector<int> res;
        unordered_map<int, int> mp;
        for(auto& digit: digits) mp[digit]++;

        for(int i=100;i<999;i+=2){
            int x = i%10;
            int y = (i/10)%10;
            int z = i/100;
            mp[x]--;
            mp[y]--;
            mp[z]--;
            if(mp[x]>=0 and mp[y]>=0 and mp[z]>=0) res.push_back(i);
            mp[x]++;
            mp[y]++;
            mp[z]++;
        }
        
        return res;   
    }
};