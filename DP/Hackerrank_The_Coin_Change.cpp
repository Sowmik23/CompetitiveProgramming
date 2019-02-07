#include <bits/stdc++.h>
using namespace std;
                               
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int arr[m+5];
    long long int visited[n+10];
    for(int i=0;i<m;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    for(int i=0;i<(n+10);i++) visited[i]=0;
    visited[0]=1;
    for(int i=0;i<m;i++)
    {
		for(int j=arr[i];j<=n;j++)
		{
			//cout<<i<<" "<<j<<endl;
			visited[j]+=visited[j-arr[i]];
			//cout<<visited[j]<<endl;
		}
	}
    cout<<visited[n];
    
    return 0;
}
