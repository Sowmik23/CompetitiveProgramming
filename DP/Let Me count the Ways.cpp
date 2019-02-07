#include <bits/stdc++.h>
using namespace std;

int arr[] = { 1,5,10,25,50 };
long long int visited[30005][7];

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
    long long ans;
    while(scanf("%d",&n)==1)
    {
        ans = dp(n,5);
        if(ans!=1) printf("There are %lld ways to produce %d cents change.\n",ans,n);
        else printf("There is only 1 way to produce %d cents change.\n",n);
    }
    
    return 0;
}
