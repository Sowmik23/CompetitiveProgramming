#include <bits/stdc++.h>
using namespace std;

///Accepted

const int MAXN = 100009;
const int MAXLOG = 25;

int n, arr[MAXN], minTable[MAXLOG][MAXN],maxTable[MAXLOG][MAXN], logs[MAXN];


void computeLogs(){
	logs[1] = 0;
	for(int i=2;i<=n;i++){
		logs[i] = logs[i/2] + 1;
	}
}

void buildSparseMinTable(){
	for(int i=0;i<=logs[n];i++){
		int curlen = 1<<i;
		
		for(int j=0;j+curlen<=n;j++){
			if(curlen==1) minTable[i][j] = arr[j];
			else {
				minTable[i][j] = min(minTable[i-1][j], minTable[i-1][j+(curlen/2)]);
			}
		}
	}
}

int getMin(int l, int r){
	int p = logs[r-l+1];
	int plen = 1<<p;
	
	return min(minTable[p][l], minTable[p][r-plen+1]);
}

void buildSparseMaxTable(){
	for(int i=0;i<=logs[n];i++){
		int curlen = 1<<i;
		
		for(int j=0;j+curlen<=n;j++){
			if(curlen==1) maxTable[i][j] = arr[j];
			else {
				maxTable[i][j] = max(maxTable[i-1][j], maxTable[i-1][j+(curlen/2)]);
			}
		}
	}
}

int getMax(int l, int r){
	int p = logs[r-l+1];
	int plen = 1<<p;
	
	return max(maxTable[p][l], maxTable[p][r-plen+1]);
}



int main(){
	
	int q, l, r;
	
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &arr[i]);
	
	computeLogs();
	buildSparseMinTable();
	buildSparseMaxTable();
	
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &l, &r);
		
		int d1 = getMin(l, r);
		int d2 = getMax(l, r);
		
		double x = (d2-d1)/2.0;
		
		int d3=0, d4=0, k1, k = l-1;
		if(k>0) d3 = getMax(0, k);
		k1 = r+1;
		if(k1<n-1) d4 = getMax(k1, n-1);
		
		//cout<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<endl;
		double y = max(d3, d4);
	
		//cout<<x<<" "<<y<<" "<<endl;
		double ans = (double)d1+ max(x,y);
		//double tst = d1+x;
		//printf("%0.1lf\n", tst);
		printf("%0.1lf\n", ans);
	}
	
	
	return 0;
}


