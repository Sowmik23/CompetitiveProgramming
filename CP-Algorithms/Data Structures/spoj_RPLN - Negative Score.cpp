#include <bits/stdc++.h>
using namespace std;


const int MAXN = 100009;
const int MAXLOG = 25;

int n, arr[MAXN], table[MAXLOG][MAXN], logs[MAXN];


void computeLogs(){
	logs[1] = 0;
	for(int i=2;i<=n;i++){
		logs[i] = logs[i/2] + 1;
	}
}

void buildSparseTable(){
	for(int i=0;i<=logs[n];i++){
		int curlen = 1<<i;
		
		for(int j=1;j+curlen<=n+1;j++){
			if(curlen==1) table[i][j] = arr[j];
			else {
				table[i][j] = min(table[i-1][j], table[i-1][j+(curlen/2)]);
			}
		}
	}
}

int getMin(int l, int r){
	int p = logs[r-l+1];
	int plen = 1<<p;
	
	return min(table[p][l], table[p][r-plen+1]);
}


int main(){
	
	int t, q, l, r;
	scanf("%d", &t);
	for(int cs=1;cs<=t;cs++) {
		scanf("%d%d", &n, &q);
		for(int i=1;i<=n;i++) scanf("%d", &arr[i]);
		
		computeLogs();
		buildSparseTable();
		
		printf("Scenario #%d:\n", cs);
		while(q--){
			scanf("%d%d", &l, &r);
			
			printf("%d\n", getMin(l, r));
		}
	}
	
	return 0;
}
