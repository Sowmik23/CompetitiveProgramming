#include <bits/stdc++.h>
using namespace std;

/* Definitions:
 * Sparse table is a data structure that allows answering queries of 
 * finding minimum or maximum in a range in an array in O(1)O(1) time 
 * after O(nlogn)O(nlogn) preprocessing.
 */


/* Applications:
 * when you need to answer a lot of queries of finding 
 * the minimum or the maximum in a range in an array
 */

// This implementation is for: 
/// Range Minimum Queries (RMQ)

const int MAXN = 105009;
const int MAXLOG = 20;

int n; /// lenght of array
int arr[MAXN], table[MAXLOG][MAXN];
int logs[MAXN]; /// logs[i] means max p such that 2^p<=i


void computeLogs(){
	logs[1] = 0;
	for(int i=2;i<=n;i++){
		logs[i] = logs[i/2] + 1;
		//cout<<logs[i]<<endl;
	}
}

void buildSparseTable(){
	for(int i=0;i<=logs[n];i++){
		int curlen = 1<<i; /// 2^i
		
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
	int plen = 1<<p; /// 2^p
	
	return min(table[p][l], table[p][r-plen+1]);
}


int main(){
	
	scanf("%d", &n);
	
	for(int i=0;i<n;i++) scanf("%d", &arr[i]);
	
	computeLogs();
	buildSparseTable();
	
	int query, l, r;
	scanf("%d", &query);
	while(query--){
		scanf("%d%d", &l, &r);
		
		printf("%d\n", getMin(l, r));
	}
	
	return 0;
}
