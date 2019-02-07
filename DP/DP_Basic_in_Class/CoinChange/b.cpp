#include<bits/stdc++.h>

using namespace std;
int n,w;
int ar[1003];
int d[1004][1004],vis[1005][1005];

int f(int w, int i)
{
    // cout<<w<<endl;
    if(w==0) return 0;
    if(w<0 or i<0) return 1e9;
    if(vis[w][i]) return d[w][i];
    for(int j=0; j<n; j++)
    {
        int a=f(w-ar[j],i-1)+1;
        d[w][i]=min(d[w][i],a);
    }
    return d[w][i];
}
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d %d",&w,&n);
    memset(d, 1e6, sizeof d);
    for(int i=0; i<n; i++) scanf("%d",&ar[i]);
    cout<<f(w,n-1)<<endl;
    return 0;
}
