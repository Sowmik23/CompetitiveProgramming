// Write your code here
#include"bits/stdc++.h"

using namespace std;
vector<int> adj[100009];
int indeg[10009],flag=0;
vector<int> vec;

 struct compare
 {
   bool operator()(const int& l, const int& r)
   {
       return l > r;
   }
 };

void topological(int n)
{
    priority_queue<int,vector<int>,compare> q;
    for(int i=1; i<=n; i++)
    {
        indeg[i]=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<adj[i].size(); j++)
        {
            int v=adj[i][j];
            indeg[v]=indeg[v]+1;
        }
    }
    
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
        }
        else
        {
            cnt++;
        }
    }
    if(cnt==n)
    {
        flag=1;
        return ;
    }
    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        vec.push_back(u);
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            indeg[v]--;
            if(indeg[v]==0)
            {
                q.push(v);
            }

        }
    }
}

int main()
{
    int n,m,u,v;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }

    topological(n);
    if(flag || vec.size()!=n)
    {
        cout<<"Sandro fails."<<endl;
    }
    else
    {
        for(int i=0; i<vec.size(); i++)
        {
            if(i)
            {
                cout<<" ";
            }
            cout<<vec[i];
        }
        cout<<endl;
    }



    return 0;
}
