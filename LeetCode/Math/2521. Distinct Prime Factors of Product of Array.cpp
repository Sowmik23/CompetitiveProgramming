// 2521. Distinct Prime Factors of Product of Array
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        
       
        //list of prime less than 1000
        vector<bool> isPrime(1000, true);
        vector<int> primes;
        isPrime[0] = isPrime[1] = false;
        // for(int i=4;i<=1000;i+=2) isPrime[i] = false;
        for(int i=2;i*i<=1000;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=1000;j+=i) isPrime[j] = false;
            }
        }
        for(int i=2;i<=1000;i++){
            if(isPrime[i]) primes.push_back(i);
        }

        set<int> st;

        for(auto& num: nums){
            int x = num;
            int i = 0;
            while(x>1 and i<primes.size()){
                int div = primes[i];
                if(x%div==0){
                    st.insert(div);
                    while(x%div==0){
                        x/=div;
                    }
                }
                i++;
            }
            if(x!=1) st.insert(x);
        }
        
        return st.size();
    }
};