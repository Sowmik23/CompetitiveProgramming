#include<bits/stdc++.h>
using namespace std;

vector<int> g[10000];
vector<int> circuit;
int circuitpos=0;

void find_circuit(int a)
{
    if(g[a].size() == 0)
    {
        circuit.push_back(a);
    }
    else
    {
        while(g[a].size()!=0)
        {
            int b = g[a].back();
            g[a].pop_back();

            for(vector<int>::iterator it = g[ b ].begin(); it != g[ b ].end(); ++it)
            {
                if(*it == a)
                {
                    g[ b ].erase( it );
                    break;
                }
            }

            find_circuit(b);
        }
        circuit.push_back(a);

    }
}

int main()
{
    int i,n,m,a,b,u=0;

    cin>>n>>m;

    for(i=0; i<m; i++)
    {
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(i=0; i<n; i++)
    {
        if(g[i].size() % 2 == 1)
        {
            u=i;
            break;
        }
    }
    //printf("%d u\n",u);

    find_circuit(u);

    for(vector<int>::iterator it=circuit.begin(); it != circuit.end(); it++)printf("%d ",*it);

    return 0;
}
