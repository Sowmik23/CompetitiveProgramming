// 1498. Number of Subsequences That Satisfy the Given Sum Condition
class Solution {
public:
    const int mod = 1e9+7;  
    int numSubseq(vector<int>& nums, int target) {
        
        //sort first
        sort(nums.begin(), nums.end());

        //precompute power of two
        int n = nums.size();
        vector<int> power(n);
        power[0] = 1;
        for(int i=1;i<n;i++){
            power[i] = (power[i-1]*2)%mod;
        }

        int cnt = 0;
        int left = 0, right = nums.size()-1;
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                // cnt = (cnt + (_pow(2, right-left))%mod)%mod;
                cnt = (cnt + power[right-left])%mod;
                left++;
            }
            else {
                right--;
            }
        }
        return cnt;
    }
private:
    int _pow(int base, int exp){
        long res = 1;
        while(exp){
            if(exp&1){ //odd
                res = (res*base)%mod;
                res = res%mod;
                exp--;
            }
            else { //even
                exp/=2;
                base = ((long)base*base)%mod;
                base = base%mod;
            }
        }
        return (int) res;
    }
};