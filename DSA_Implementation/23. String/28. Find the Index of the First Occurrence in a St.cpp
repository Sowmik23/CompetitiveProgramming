// 28. Find the Index of the First Occurrence in a String


// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/solutions/3121002/find-the-index-of-the-first-occurrence-in-a-string/



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
        //Time:  O(1)
        //Space: O(1)

        const int RADIX_1 = 26;
        const int RADIX_2 = 27;
        const int MOD_1 = 1000000033;
        const int MOD_2 = INT_MAX;

        int m = needle.size();
        int n = haystack.size();

        if(n<m) return -1;

        long MAX_WEIGHT_1 = 1;
        long MAX_WEIGHT_2 = 1;
        for(int i=0;i<m;i++){
            MAX_WEIGHT_1 = (MAX_WEIGHT_1*RADIX_1)%MOD_1;
            MAX_WEIGHT_2 = (MAX_WEIGHT_2*RADIX_2)%MOD_2;
        }

        pair<long, long> hashNeedle = hashPair(needle, m, RADIX_1, RADIX_2, MOD_1, MOD_2);
        pair<long, long> hashHay = {0, 0};

        for(int i = 0;i<=n-m;i++){
            if(i==0){
                hashHay = hashPair(haystack, m, RADIX_1, RADIX_2, MOD_1, MOD_2);
            }
            else {
                //apply rolling hash and compute /// dba=26^2*3+26^1*1+26^0*0=2054
                hashHay.first = ((hashHay.first*RADIX_1)%MOD_1 
                - ((int)(haystack[i-1]-'a')*MAX_WEIGHT_1)%MOD_1
                + (int)(haystack[i+m-1]-'a')+MOD_1)%MOD_1;

                hashHay.second = ((hashHay.second*RADIX_2)%MOD_2 
                - ((int)(haystack[i-1]-'a')*MAX_WEIGHT_2)%MOD_2
                + (int)(haystack[i+m-1]-'a')+MOD_2)%MOD_2;
            }
            if(hashNeedle.first==hashHay.first and hashNeedle.second==hashHay.second) return i;
        }
        return -1;
    }
private:
    pair<long, long> hashPair(string str, int m, int RADIX_1, int RADIX_2, int MOD_1, int MOD_2){
        long hash1 = 0;
        long hash2 = 0;
        long factor1 = 1;
        long factor2 = 1;

        for(int i=m-1;i>=0;i--){
            hash1+=((str[i]-'a')*factor1)%MOD_1;
            factor1 = (factor1*RADIX_1)%MOD_1;
            hash2+=((str[i]-'a')*factor2)%MOD_2;
            factor2 = (factor2*RADIX_2)%MOD_2;
        }
        return {hash1%MOD_1, hash2%MOD_2};
    }
};