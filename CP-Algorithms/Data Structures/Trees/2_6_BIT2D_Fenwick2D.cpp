#include <bits/stdc++.h>
using namespace std;

//Problem: https://www.spoj.com/problems/MATSUM/
/// Best hard level problem
/// Fenwick2D/ BIT2D

const int MAXN = 1026;
int n, BITree[MAXN][MAXN], arr[MAXN][MAXN];


int getSum(int x, int y){
	int i, j;
	int sum =0;
	for (i = x; i > 0; i &= i-1) {
		for (j = y; j > 0; j &= j-1) {
			sum += BITree[i][j];
		}
	}
	return sum;
}


int Sum(int x1, int y1, int x2, int y2) {
	
	int ans = getSum(x2, y2) - getSum(x2, y1-1) - getSum(x1-1, y2) + getSum(x1-1, y1-1);
	return ans;
}


void updateBIT(int x, int y, int val){
	int i, j;
	for (i = x; i <= n; i += i&-i) {
		for (j = y; j <= n; j += j&-j) {
			BITree[i][j] += val;
		}
	}
}

int main(){
	
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	int t, x, y, num, x1, y1, x2, y2;
	char str[5];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		
		//updateBIT(1, n, 0);
		memset(BITree, 0, sizeof(BITree));
		memset(arr, 0, sizeof(arr));
		
		while(1){
			scanf("%s", str);
			
			if(str[1]=='E') {
				scanf("%d%d%d", &x, &y, &num);
				x = x+1;
				y = y+1;
				updateBIT(x, y, num-arr[x][y]);
				arr[x][y] = num;
			}
			else if(str[1]=='U'){
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				x1 = x1 + 1;
				x2 = x2 + 1;
				y1 = y1 + 1;
				y2 = y2 + 1;
				printf("%d\n", Sum(x1, y1, x2, y2));
			}
			else if(str[1]=='N') break;
		}
	}

	return 0;
}

/*
1
4
SET 0 0 1
SUM 0 0 3 3
SET 2 2 12
SUM 2 2 2 2
SUM 2 2 3 3
SUM 0 0 2 2
END
*/
