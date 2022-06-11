class Solution {
public:
    // 3 D dp vector, as we dicused, We will give it maximum size,
    //see Constraints, 1 <= strs.length <= 600 and 1 <= m, n <= 100
    int dp[601][101][101]; 

    
    int findMaxForm(vector<string>& strs, int m, int n) {
     
        
        //return recursive(strs, m, n);
        
        // we redfine m and n as maxzero and maxOne respectively, for better clarification.
        int maxZero = m; 
        int maxOne = n;
        
        memset(dp, -1, sizeof(dp)); // intially, putting -1 in dp
        
        /* parameters of solve-
        1) First parameter is 'i', by which we move in our array of strings.
        2) Second parameter is the variable who keeps record of count of ones. (we name it as one)
        3) Third parameter is the variable who keeps record of count of zeroes. (we name it as zero)
        4) Fourth parameter is maxZero, the maximum zeros we are allowed to take.
        5) Fifth parameter is maxOne, the maximum ones we are allowed to take. 
        6) Last Sixth parameter is the array itself.
        */
        
        // return solve function
        return solve(0, 0, 0, maxZero, maxOne, strs);
    }
private:
    int recursive(vector<string> &strs, int m, int n){
        
        if(m>=0 and n>=0) return 1;
        if(m<0 or n<0) return 0;
        
        int x = INT_MIN;
        for(int i=0;i<strs.size();i++){
            
            string s = strs[i];
            for(int j=0;j<s.size();j++){
                if(s[j]=='0') m--;
                else n--;
            }
            x = max(x, 1+recursive(strs, m-1, n-1));
        }
        
        return x;
    }
    
    
// Count one and Zero function take string as parameter and count the number of ones and zeroes present in the string and return the counts.
pair<int, int> countOneAndZero(string s)
    {
        int one = 0, zero = 0;
        
        for(int i = 0; i < s.length(); i++) // travel in the string
        {
            if(s[i] == '1') // if == '1', then add to one
                one++;
            else            // otherwise add to zero
                zero++;
        }
        
        return {one, zero};
    }
    
    int solve(int i, int one, int zero, int& maxZero, int& maxOne, 
             vector<string>& arr)
    {
        if(i >= arr.size()) // if ith index crosses the length then return 0
            return 0;
        
        // if any of the count, crosses the criteria of having maximum one
        // or zero, then return 0
        if(one > maxOne || zero > maxZero)
            return 0;
        
        // if it is already computed, then no need to do computation again,
		//return from here itself
        if(dp[i][one][zero] != -1)
        {
            return dp[i][one][zero];
        }
        
        /* what we discused:-
        for every ith index i, we have two option, whether to include it
         in our answer or not, if include then add the count of 
         ones and zeros from that string */
        
        // pair p contains, the number of ones and zeroes present in the string of ith index of vector arr.
        pair<int, int> p = countOneAndZero(arr[i]);
        
        /* we declare three variables -
        1) ans1, If adding the count of ones and zeroes at ith index in arr,
        does not crosses our limit, then to include this in our answer.
        2) ans2, If adding the count of ones and zeroes at ith index in arr,
        does not crosses our limit, then not to include this in our answer.
        3) ansWithout, If adding the count of ones and zeroes at ith index in arr, crosses our limit, then not to include this in our answer.
        */
        
        int ans1 = 0, ans2 = 0, ansWithout = 0;
        
        // adding count of current index, not to cross our limit then-
        if(one + p.first <= maxOne && zero + p.second <= maxZero)
        {
            // ans1, including it in our answer
            ans1 = 1 + solve(i + 1, one + p.first, zero + p.second, 
                           maxZero, maxOne, arr);
            
            // not including in our answer.
            ans2 = solve(i + 1, one, zero, maxZero, maxOne, arr);
        }
        else // if crossing limit, obviously not to take
        {
            ansWithout = solve(i + 1, one, zero, maxZero, maxOne, arr);
        }
        
        // and at last return the maximum of them
        return dp[i][one][zero] = max({ans1, ans2, ansWithout});
    }
};
