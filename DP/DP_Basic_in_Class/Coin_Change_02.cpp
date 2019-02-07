#include <bits/stdc++.h>
using namespace std;
								/* minimum number of coins to make n from 1 to n number of coins */
int arr[] = { 9,6,5,1 };
long long int visited[300005][7];

long long int dp(int n, int k)
{
    if(n==0) return 1;
    if(k<=0 and n>0) return 0;
    if(n<0) return 0;
    if(visited[n][k]!=-1) return visited[n][k];
    if(visited[n][k]==-1) 
    {
		int a = dp(n,k-1);
		int b = dp(n-arr[k-1]+1,k);
		return visited[n][k] = min(a,b);
    }
    
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
