#include"bits/stdc++.h"

using namespace std;

vector<int> adj[100009];

int visit[100009],len[100009];

int dfs(int u)
{

    visit[u]=1;
    int d=0;
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(!visit[v])
        {
            d+=dfs(v)+1;
        }

    }

    visit[u]=0;
    len[u]=d;
    return len[u];
}
void graph(int n)
{
    for(int i=1;i<=n;i++)
    {
        visit[i]=0;
        len[i]=-1;
    }
}

int main()
{
    int t,Case=0;
    cin>>t;
    while(t--)
    {
        int n,i,u,v,ans,temp=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
        Case++;
        graph(n);
        for(i=1;i<=n;i++)
        {
            if(len[i]==-1)
            {
                dfs(i);
            }

            if(len[i]>temp)
            {
                temp=len[i];
                ans=i;
            }

        }
        cout<<"Case "<<Case<<": "<<ans<<endl;
        for(i=0;i<=n;i++)
        {
            adj[i].clear();
        }


    }

    return 0;

}
