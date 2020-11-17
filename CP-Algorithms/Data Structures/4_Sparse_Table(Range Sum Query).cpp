#include <bits/stdc++.h>
using namespace std;

const int MAXN = 109999;
const int MAXLOG = 20;

int n, arr[MAXN], table[MAXLOG][MAXN], logs[MAXN];


void computeLogs(){
	logs[1] = 0;
	for(int i=2;i<=n;i++){
		logs[i] = logs[i/2] + 1;
	}
}


void buildSparseTable(){
	for(int i=0;i<=logs[n];i++){
		int curlen = 1<<i;  /// 2^i
		
		for(int j=0;j+curlen <=n;j++){
			if(curlen==1) table[i][j] = arr[j];
			else {
				table[i][j] = table[i-1][j] + table[i-1][j+(curlen/2)];
			}
		}
	}
}

long long getSum(int l, int r){ 	
	//int p = logs[r-l+1];
	//int len = 1<<p;
	long long sum = 0;
	for(int j=20;j>=0;j--){
		if((1<<j)<=r-l+1){
			sum+=table[j][l];
			l+= 1<<j;
		}
	}
	
	return sum;
}



int main(){
	
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &arr[i]);
	
	computeLogs();
	buildSparseTable();
	
	int queries, l, r;
	scanf("%d", &queries);
	while(queries--){
		scanf("%d%d", &l, &r);
		
		printf("%lld\n", getSum(l, r));
	}
	
	return 0;
}
