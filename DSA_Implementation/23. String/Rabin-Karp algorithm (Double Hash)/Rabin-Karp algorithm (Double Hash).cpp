// Rabin-Karp algorithm (Double Hash)

class Solution {
	public:
    int strStr(string haystack, string needle) {

    	int m = needle.size();
    	int n = haystack.size();
    	if(m>n) return -1;

        const int radix1 = 26;
        const int radix2 = 27;
    	const int mod1 = 1000000033;
        const int mod2 = INT_MAX;
    	long maxWeight1 = 1, maxWeight2 = 1;

    	for(int i=0;i<m;i++){
    		maxWeight1 = (maxWeight1*radix1)%mod1;
    		maxWeight2 = (maxWeight2*radix2)%mod2;
    	}

    	pair<long, long> hashNeedle = hashPair(needle, m, mod1, mod2, radix1, radix2);
    	pair<long, long> hashHay = {0, 0};

    	for(int i=0;i<=n-m;i++){
    		if(i==0){
    			hashHay = hashPair(haystack, m, mod1, mod2, radix1, radix2);
    		}
    		else {
    			hashHay.first = ( (hashHay.first*radix1)%mod1 - ((int)(haystack[i-1]-'a')*maxWeight1)%mod1 + (int)(haystack[i+m-1]-'a')+mod1 )%mod1;
    			hashHay.second = ( (hashHay.second*radix2)%mod2 - ((int)(haystack[i-1]-'a')*maxWeight2)%mod2 + (int)(haystack[i+m-1]-'a')+mod2 )%mod2;
    		}
    		if(hashHay.first==hashNeedle.first and hashHay.second==hashNeedle.second) return i;
    	}
    	return -1; 
    }
 	private:
 	pair<long, long> hashPair(string str, int m, int mod1, int mod2, int radix1, int radix2){

 		long hash1 = 0, hash2 = 0;
 		long factor1 = 1, factor2 = 1;

 		for(int i=m-1;i>=0;i--){
 			hash1 += ((str[i]-'a')*factor1)%mod1;
 			factor1 = (factor1*radix1)%mod1;
 			hash2 += ((str[i]-'a')*factor2)%mod2;
 			factor2 = (factor2*radix2)%mod2;
 		}
 		return {hash1%mod1, hash2%mod2};
 	} 
}


int main() {

	Solution solution = new Solution();
	int x = solution.strStr("sowmiksarker", "sowmik");
	cout<<x<<endl;

	return 0;
}