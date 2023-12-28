// Knuth–Morris–Pratt Algorithm(KMP)

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        //brute force
        //Time: O(m*n)
        //Space: O(1)

        /*
        if(haystack.size()<needle.size()) return -1;
        for(int i=0;i<=haystack.size()-needle.size();i++){
            int j = 0, k = i;
            while(haystack[k]==needle[j]){
                j++;
                k++;
                if(j==needle.size()) return i;
            }
        }
        return -1;
        */

        // Rabin-Karp algorithm (Double Hash)
        //Time:  O(n)
        //Space: O(1)
        /*
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

        */

        //Knuth–Morris–Pratt Algorithm
        //Time: O(n)
        //Space: O(m)
        //Keywords to learn: prefix, suffix, proper prefix, proper suffix, border, longest border(lps)

        int m = needle.size();
        int n = haystack.size();
        if(m>n) return -1;

        //at first implement lps(longest_border) array for needle
        vector<int> longest_border(m);
        int prev = 0;
        int i = 1; //longest_border[0] will always be 0
        while(i<m){
            if(needle[i]==needle[prev]){
                prev+=1;
                longest_border[i] = prev;
                i++;
            }
            else {
                if(prev==0){
                    longest_border[i] = 0;
                    i++;
                }
                else prev = longest_border[prev-1];
            }
        }

        //now implement kmp technique
        i = 0;
        int j = 0;
        while(j<n){
            if(needle[i]==haystack[j]){
                i++;
                j++;
                if(i==m) return j-m;
            }
            else {
                if(i>0) i = longest_border[i-1];
                else j++;
            }
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
};