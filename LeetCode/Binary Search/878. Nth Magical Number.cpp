#define ll long long int   //macro

class Solution {
public:
    int mod = 1e9 + 7;
    int nthMagicalNumber(int n, int a, int b) {
        
        /*
        Number of numbers that are divisible by a is: [m/a]
        Number of numbers that are divisible by b is: [m/b]
        
        Number of numbers that are divisible by both a and b is: [m/lcm(a, b)]
        
        N = [m/a] + [m/b] - [m/lcm(a, b)]
        
        lcm(a, b) = (a*b)/gcd(a, b)
        
        */
        
        //now do a binary search
        
        ll low = 1, high = LONG_LONG_MAX;
        ll mid, target;
        ll lcmab = lcm(a, b);
        
        while(low<high){
            mid = low+(high-low)/2;
            target = mid/a + mid/b - mid/lcmab;
            
            if(target<n){
                low = mid+1;
            }
            else {
                high = mid;
            }
        }
        
        return high%mod;
    }
    
private:
    ll gcd(ll a, ll b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
    
    ll lcm(ll a, ll b){
        return (a*b)/gcd(a, b);
    }
};
