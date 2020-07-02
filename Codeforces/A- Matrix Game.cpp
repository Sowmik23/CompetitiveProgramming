#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n,m;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d%d",&n,&m);
		int arr[n][m];
		int cnt=0;
		
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
				scanf("%d",&arr[j][k]);
			}
		}
		
		int free_row = 0;
		int free_col = 0;
		for(int j=0;j<n;j++)
		{
			bool flag= false;
			
			for(int k=0;k<m;k++)
			{
				if(arr[j][k] !=0){
					flag = true;
					break;
				}
			}
			if(flag==false) free_row++;
		}
		//cout<<free_row<<endl;
		
		for(int j=0;j<m;j++)
		{
			bool f= false;
			
			for(int k=0;k<n;k++)
			{
				//printf("%d ",arr[k][j]);
				if(arr[k][j] !=0){
					f = true;
					break;
				}
			}
			//cout<<endl;
			if(f==false) free_col++;
		}
		cnt = min(free_row, free_col);
		
		//cout<<free_row<<" "<<free_col<<endl;
		
		if(cnt%2!=0) printf("Ashish\n");
		else printf("Vivek\n");
	}
	
	
	return 0;
}
