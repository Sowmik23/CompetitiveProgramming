#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	scanf("%d",&n);

	int grid[n][n];
	int x = 0;
	for (int i = 0; i < n/2; ++i)
	{
		for (int j = 0; j < n/2; ++j)
		{
			grid[i][j] = 4*x;
			grid[i][j+n/2] = 4*x + 1;
			grid[i+n/2][j] = 4*x + 2;
			grid[i+n/2][j+n/2] = 4*x + 3;
			x++;
		}
	}

	// // Check XOR value
	// int res;
	// // check rows
	// for (int i = 0; i < n; ++i)
	// {
	// 	res = grid[i][0];
	// 	for(int j=1;j<n;j++){
	// 		res = res ^ grid[i][j];
	// 	}
	// 	printf("%d\n",res );
	// }
	// // check columns
	// for (int j = 0; j < n; ++j)
	// {
	// 	res = grid[0][j];
	// 	for(int i=1;i<n;i++){
	// 		res = res ^ grid[i][j];
	// 	}
	// 	printf("%d ",res );
	// }
	// printf("\n");

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d ",grid[i][j]);
		}
		printf("\n");
	}


	return 0; 
}