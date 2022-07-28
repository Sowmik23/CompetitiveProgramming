#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char A,B,input[100],input2[20];
int ans,f,total;
int res[30][30];
int visited[30],v1[30];



void augment(int minFlow,int x)
{
	if(x==0)
	{
		f = minFlow;
		return;
	}
	else if(v1[x]!=-1)
	{
		augment(min(minFlow,res[v1[x]][x]),v1[x]);
		res[v1[x]][x] -=f;
		res[x][v1[x]] +=f;
	}
}

void print_letter(int i)
{
	for(int j=1;j<27;j++)
	{
		if(res[i][j] ==1)
		{
			printf("%c",'A' + j-1);
			return ;
		}
	}
	printf("_");
}

int main()
{
	while(1)
	{
		if(gets(input)==0) break;
		memset(res,0,sizeof(res));
		total = 0;
		
		while(gets(input))
		{
			if(strcmp(input,"")==0) break;
			sscanf(input,"%c%c %s",&A,&B,input2);
			res[0][A - 'A' + 1] = B - '0';
			total +=B - '0';
			for(int i=27;i<37;i++)  //27 to 36 are computers;
			{
				res[i][37] = 1;
			}
			
			ans = 0;
			while(1)
			{
				memset(v1,-1,sizeof(visited));
				memset(visited,0,sizeof(visited));
				visited[0] = 1;
				queue<int> mq;
				mq.push(0);
				f = 0;
				while(!mq.empty())
				{
					int top = mq.front();
					if(top==37) break;
					mq.pop();
					for(int i=0;i<38;i++)
					{
						if(res[top][i]>0 and !visited[i])
						{
							visited[i] = 1;
							mq.push(i);
							v1[i] = top;
						}
					}
				}
				augment(INT_MAX,37);
				if(f==0) break;
				ans +=f;
			}
			if(ans==total)
			{
				for(int i=27;i<37;i++)
				{
					print_letter(i);
				}
			}
			else printf("!");
			printf("\n");
		}	
	}
	
	return 0;
}
