// 1814. Count Nice Pairs in an Array
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        
        //Hash Table + Math
        unordered_map<int, int> mp;
        for(auto& num: nums){
            int revNum = rev(num);
            mp[num-revNum]++;
        }

        long res = 0;
        for(auto& m: mp){
            int n = m.second;
            n--;
            res =(res+((long)n*(n+1)/2)%mod)%mod;
        }
        return res%mod;
    }
private:
    const int mod = 1e9+7;
    int rev(int num){
        int x = 0;
        while(num){
            x = x*10 + num%10;
            num/=10;
        }
        return x;
    }
};