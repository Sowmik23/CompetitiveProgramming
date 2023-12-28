// 823. Binary Trees With Factors

class Solution {
public:
    const int mod = 1e9+7;

    int numFactoredBinaryTrees(vector<int>& arr) {
        
        //Time: O(n√n)
        /*
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> mp;
        long long ans = 0;

        for(auto x: arr){
            mp[x] = 1;
            int sqrt_x = sqrt(x);

            for(int j=0;arr[j]<=sqrt_x;j++){
                int y = arr[j];
                if(x%y==0) {
                    int z = x/y;
                    int c = (y==z)?1:2;
                    if(mp.count(z)){
                        mp[x] = (mp[x]+mp[y]*mp[z]*c)%mod;
                    }
                }
            }
            ans = (ans+mp[x])%mod;
        }
        return ans;
        */

        sort(arr.begin(), arr.end()); // Sort the array.

        unordered_map<int, long long> mp; // Use a map to store the number of trees for each value.

        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = 1; // A single node tree with the value arr[i].
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) { // If arr[j] is a factor of arr[i].
                    int factor = arr[i] / arr[j];
                    if (mp.count(factor)) {
                        mp[arr[i]] = (mp[arr[i]] + mp[arr[j]] * mp[factor]) % mod;
                    }
                }
            }
        }

        long long result = 0;
        for (auto& entry : mp) {
            result = (result + entry.second) % mod;
        }

        return static_cast<int>(result);
    }
};