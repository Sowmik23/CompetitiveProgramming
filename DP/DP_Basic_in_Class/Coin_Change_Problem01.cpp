#include <bits/stdc++.h>
using namespace std;
								/* Number of ways to make n coin from 1 to n number of coins */
int arr[] = { 50,25,10,5,1 };
long long int visited[300005][7];

long long int dp(int n, int k)
{
    if(n==0) return 1;
    if(k<=0 and n>0) return 0;
    if(n<0) return 0;
    if(visited[n][k]!=-1) return visited[n][k];
    if(visited[n][k]==-1) 
    {
        visited[n][k] = dp(n,k-1) + dp(n-arr[k-1],k);
    }
    return visited[n][k];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int n;
    for(int i=0;i<=30000;i++)
    {
        for(int j=0;j<=5;j++)
        {
            visited[i][j]=-1;
        }
    }
    while(scanf("%d",&n)==1)
    {
        
        printf("%lld\n",dp(n,5));
    }
    
    return 0;
}
