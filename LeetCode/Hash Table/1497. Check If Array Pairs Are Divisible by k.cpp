// 1497. Check If Array Pairs Are Divisible by k
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        // MATH: Read the equations from down to up
        // a+b = x%k = 0 [Main equation]
        // a%k = x
        // b%k = k-x
        // a = m*k + x;
        // b = n*k + k-x;

        // a+b = mk+x + n*k+k-x;
        //     = (m+n+1)k => (a+b)%k = 0

        unordered_map<int, int> mp;
        for(auto& num: arr){
            int x = num%k;
            if(x<0) x+=k;
            mp[x]++;
        }

        if(mp[0]%2!=0) return false;

        for(int i=1;i<=k/2;i++){
            if(mp[i]!=mp[k-i]) return false;
        }

        return true;
    }
};