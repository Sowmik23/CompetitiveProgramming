// Given N friends, each one can remain single or can be paired up with some other
// friend. Each friend can be paired only once. Find out the total number of ways
// in which friends can remain single or can be paired up.
// Note: Since answer can be very large, return your answer mod 10^9+7.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Test case:
// 1 = 1
// 2 = 2
// 3 = 4
// 4 = 10
// 5 = 26
// 6 = 76
// so it follows this fibonacci pattern!!!
// c = b + (i - 1) * a;


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    const int mod = 1e9+7;
    int countFriendsPairings(int n)
    {

        //recursive: TLE
        // return recursive(n)%mod;

        //recursion with memoization
        vector<long> memo(n+1, -1);
        return recursionWithMemo(memo, n);


        //iterative/tabulation
        /*
        if(n<=2) return n;
        long a = 1;
        long b = 2;
        long c;
        for(int i=3;i<=n;i++){
            c = (b+((i-1)*a)%mod)%mod;
            a = b%mod;
            b = c%mod;
        }
        return c%mod;
        */
    }
private:
    long recursive(int i){
        if(i<=2) return i;
        return recursive(i-1)%mod+((i-1)*recursive(i-2)%mod)%mod;
    }
    long recursionWithMemo(vector<long> &memo, int i){
        if(i<=2) return i;
        if(memo[i]!=-1) return memo[i]%mod;
        memo[i] = recursionWithMemo(memo, i-1)%mod+((i-1)*recursionWithMemo(memo, i-2)%mod)%mod;
        return memo[i]%mod;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n);
    	cout<<endl;
    }
}

// } Driver Code Ends
