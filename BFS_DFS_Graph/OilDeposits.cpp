#include <bits/stdc++.h>
using namespace std;
int m,n;
char str[101][101];
int arrX[] = {0,0,1,-1,1,1,-1,-1};
int arrY[] = {1,-1,0,0,1,-1,1,-1};

void DFS(int x,int y)
{
    if(x<0 || y<0 || x==m ||y==n) return ;
    if(str[x][y] != '@') return;
    if(str[x][y] =='@')  str[x][y] = '*' ;
    for(int i=0;i<8;i++)
    {
        DFS( x+arrX[i],y+arrY[i]);
    }
}

int main()
{
    int cnt;
    while(scanf("%d%d",&m,&n))
    {
        if(m==0 && n==0) break;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>str[i][j];
            }
        }
        cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(str[i][j]!='*')
                {
                    DFS(i,j);
                    cnt++;
                }
                //cout<<str[i][j];
            }
           // cout<<endl;
        }
        printf("%d\n",cnt);
    }

    return 0;
}
