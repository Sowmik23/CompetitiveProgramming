#include <bits/stdc++.h>
using namespace std;

//2D Binary Indexed Tree/Fenwick Tree


const int MAXN = 1002;
int n = 1000;
int arr[MAXN][MAXN], BITree[MAXN][MAXN];


int Sum(int x, int y){
	int i, j;
	int sum =0;
	for (i = x; i > 0; i &= i-1) {
		for (j = y; j > 0; j &= j-1) {
			sum += BITree[i][j];
		}
	}
	return sum;
}


int getSum(int x1, int y1, int x2, int y2){
	return (Sum(x2, y2) - Sum(x1-1, y2) - Sum(x2, y1-1) + Sum(x1-1, y1-1));
}

void updateBIT(int x, int y, int val){
	int i, j;
	for (i = x; i <= 1001; i += i&-i) {
		for (j = y; j <= 1001; j += j&-j) {
			BITree[i][j] += val;
		}
	}
}


int main(){
	
	//ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	int t, q, x, x1, y1, x2, y2;
	scanf("%d", &t);
	for(int cs=1;cs<=t;cs++){
		
		memset(arr, 0, sizeof(arr));
		memset(BITree, 0, sizeof(BITree));
		
		printf("Case %d:\n", cs);
		scanf("%d", &q);
		for(int c=1;c<=q;c++){
			scanf("%d", &x);
			if(x==0){
				scanf("%d%d", &x1, &y1);
				x1++, y1++;
				if(arr[x1][y1]!=1) {
					updateBIT(x1, y1, 1);
					arr[x1][y1] = 1;
				}
			}
			else if(x==1){
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				x1++, y1++, x2++, y2++;
				printf("%d\n", getSum(x1, y1, x2, y2));
			}
		}
	}
	
	
	return 0;
}
