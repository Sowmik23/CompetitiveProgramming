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
				table[i][j] = max(table[i-1][j], table[i-1][j+(curlen/2)]);
			}
		}
	}
}

int getMax(int l, int r){
	int p = logs[r-l+1];
	int plen = 1<<p;
	
	return max(table[p][l], table[p][r-plen+1]);
}


int main(){
	
	int q, l, r;
	
	scanf("%d%d", &n, &q);
	for(int i=1;i<=n;i++) scanf("%d", &arr[i]);
	
	computeLogs();
	buildSparseTable();
	
	int cnt=0;
	while(q--){
		scanf("%d%d", &l, &r);
		
		int d;
		
		if(l<=r){
			d = getMax(l, r-1);
			if(d<=arr[l]) cnt++;
		}
		else {
			d = getMax(r+1, l);
			if(d<=arr[l]) cnt++;
		}
	}
	printf("%d\n", cnt);
	
	return 0;
}


