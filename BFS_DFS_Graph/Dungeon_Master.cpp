#include <bits/stdc++.h>
using namespace std;

int l,r,c;
vector<vector<string> >str1;
vector<string>str2;
int visited[31][31][31];

int move_i[]={0,0,0,0,-1,1 };
int move_j[]={0,0,-1,1,0,0 };
int move_k[]={-1,1,0,0,0,0 };		

struct node
{
	int a,b,c,t=0;
	node(int w,int x,int y,int z)
	{
		a=w;
		b=x;
		c=y;
		t=z;
	}
};

void BFS(int x,int y,int z)
{
	queue<node>mq;
	mq.push(node(x,y,z,0));
	visited[x][y][z]=1;
	while(!mq.empty())
	{
		node top = mq.front();
		mq.pop();
		if(str1[(top.a)][(top.b)][(top.c)]=='E')
		{
			cout<<"Escaped in "<<top.t<<" minute(s)."<<endl;
			return ;
		}
		for(int i=0;i<6;i++)
		{
			int xx=top.a + move_i[i];
			int yy=top.b + move_j[i];
			int zz=top.c + move_k[i];
			if(xx>=0 && xx<l && yy>=0 && yy<r && zz>=0 && zz<c && str1[xx][yy][zz]!='#' && visited[xx][yy][zz]==0)
			{
				mq.push(node(xx,yy,zz,(top.t)+1));
				visited[xx][yy][zz]=1;
			}
		}
	}
	cout<<"Trapped!"<<endl;
}

int main()
{
	while(1)
	{
		scanf("%d%d%d",&l,&r,&c);
		if(l==0 && r==0 && c==0) break;
		str1.clear();
		memset(visited,0,sizeof(visited));
		for(int i=0;i<l;i++)
		{
			string s;
			str2.clear();
			for(int j=0;j<r;j++)
			{
				cin>>s;
				str2.push_back(s);
			}
			cin.get();
			str1.push_back(str2);
		}
		
		int x,y,z,d=0;
		for(int i=0;i<l;i++)
		{
			for(int j=0;j<r;j++)
			{
				for(int k=0;k<c;k++)
				{
					if(str1[i][j][k]=='S')
					{
						x=i,y=j,z=k;
						d=1;
						break;
					}
				}
				if(d==1) break;
			}
			if(d==1) break;
		}
		BFS(x,y,z);		
	}
	
	return 0;
}
