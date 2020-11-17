#include <bits/stdc++.h>
using namespace std;

/// Basic 2D Binary Indexed Tree/Fenwick Tree


typedef long long ll;
const int MAXN = 2005;

int n, m, arr[MAXN][MAXN];
ll BITree[MAXN][MAXN];


ll Sum(int x, int y){
	int i, j;
	ll sum =0;
	for (i = x; i > 0; i &= i-1) {
		for (j = y; j > 0; j &= j-1) {
			sum += BITree[i][j];
		}
	}
	return sum;
}


ll getSum(int x1, int y1, int x2, int y2){
	return (Sum(x2, y2) - Sum(x1-1, y2) - Sum(x2, y1-1) + Sum(x1-1, y1-1));
}


void updateBIT(int x, int y, int val){
	int i, j;
	for (i = x; i <= n; i += i&-i) {
		for (j = y; j <= m; j += j&-j) {
			BITree[i][j] += val;
		}
	}
}


int main(){
		
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	int q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d", &arr[i][j]);
			
			updateBIT(i, j, arr[i][j]);
		}
	}
	
	
	int x, p, x1, y1, x2, y2;
	while(q--){
		scanf("%d", &x);
		if(x==1){
			scanf("%d%d%d", &x1, &y1, &p);
			
			updateBIT(x1, y1, p);
		}
		else if(x==2) {
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			
			printf("%lld\n", getSum(x1, y1, x2, y2));
		} 
	}
	
	
	return 0;
}

/*
6 5 8
1 2 3 4 5
1 2 3 4 5
6 6 6 6 6
5 4 3 2 1
5 4 3 2 1
6 6 6 6 6
2 1 1 6 5
2 1 1 2 4
2 4 2 5 4
1 5 4 4
1 1 1 665
2 1 1 6 5
2 1 1 2 4
2 4 2 5 4
*/

