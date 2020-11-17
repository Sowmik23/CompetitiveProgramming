#include <bits/stdc++.h>
using namespace std;


const int MAXN = 100009;
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
		
		int curlen = 1<<i; ///2^i
		for(int j=0;j+curlen<=n;j++){
			if(curlen==1) table[i][j] = arr[j];
			else {
				table[i][j] = min(table[i-1][j], table[i-1][j+(curlen/2)]);
			}
		}
	}
}

int getMin(int l, int r){
	int p = logs[r-l+1];
	int plen = 1<<p;  ///2^p
	
	return min(table[p][l], table[p][r-plen+1]);
}


int main(){
	
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &arr[i]);
	
	computeLogs();
	buildSparseTable();
	
	int q, l, r;
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &l, &r);
		
		printf("%d\n", getMin(l, r));
	}
	
	return 0;
}
