#include <bits/stdc++.h>
using namespace std;
char str[101][101],ins[50009];
int n,m,s,x,y,pos;

int process(int x,int y)
{
	int a,b;
	int cnt=0;
	for(int i=0;i<s;i++)
	{	
		if(ins[i]=='D')
		{
			pos=(pos+1)%4;
		}
		else if(ins[i]=='E')
		{
			pos=pos-1;
			if(pos<0) pos=3;
		}
		else if(ins[i]=='F')
		{
			a=x;
			b=y;
			if(pos==0) a--;
			else if(pos==1) b++;
			else if(pos==2) a++;
			else if(pos==3) b--;
			
			if(a<0 || a>=n || b<0 || b>=m || str[a][b]=='#') continue;
			else 
			{
				str[x][y]='.';
				if(str[a][b]=='*') cnt++;
				x=a;
				y=b;
			}
		}	
	}
	return cnt;
}

int main()
{
	while(1)
	{
		cin>>n>>m>>s;
		if(n==0 && m==0 && s==0) break;
		scanf(" ");
		for(int i=0;i<n;i++)
		{
			scanf("%s",str[i]);
		}
		
		scanf("%s",ins);
		
		int p=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(str[i][j]=='N' || str[i][j]=='L' || str[i][j]=='S' || str[i][j]=='O')
				{
					x=i;
					y=j;
					p=1;
					break;
				}
			}
			if(p==1) break;
		}
		//cout<<x<<" "<<y<<endl;
		
		if(str[x][y]=='N') pos = 0;
		else if(str[x][y]=='L') pos = 1;
		else if(str[x][y]=='S') pos = 2;
		else if(str[x][y]=='O') pos = 3;
		
		cout<<process(x,y)<<endl;
	
	}
	
	return 0;
}
