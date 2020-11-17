#include <bits/stdc++.h>
using namespace std;



const int MAXN = 100009;
const int MAXLOG = 25;

int n, arr[MAXN], table[MAXLOG][MAXN], logs[MAXN];

vector<int> v[MAXN];
int End[MAXN];

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
	
	memset(End, 0, sizeof(End));
	arr[n+1] = 0;
	for(int i=n;i>=1;i--){
		if(arr[i+1]==1 and arr[i]==1){
			End[i] = End[i+1];
		}
		else if(arr[i]==1){
			End[i] = i;
		}
	}
}

int getMin(int l, int r){
	int p = logs[r-l+1];
	int plen = 1<<p;
	
	return min(table[p][l], table[p][r-plen+1]);
}


//binary search
void solve(int l, int r){
	
	int left_pos, right_pos;
	int len = 0;
	int now = l;
	
	while(now<=l){
		int start = lower_bound(v[1].begin(), v[1].end(), now) - v[1].begin();
		
		if(start==v[1].size()) break;
		start = v[1][start];
		int end = min(End[start], r);
		
		int tmp = end - start  + 1;
		if(tmp>len) {
			len = tmp;
			left_pos = start;
			right_pos = end;
		}
		now = end + 1;
	}
	printf("%d %d\n", left_pos, right_pos);
}


int main(){
	
	int t, q, l, r;
	scanf("%d", &t);
	for(int cs=1;cs<=t;cs++) {
		scanf("%d%d", &n, &q);
		for(int i=1;i<=n;i++) scanf("%d", &arr[i]);
		
		computeLogs();
		buildSparseTable();
		
		printf("Case %d:\n", cs);
		while(q--){
			scanf("%d%d", &l, &r);
			
			int k = getMin(l, r);
			
			/// Main tasks start here...
			if(k==0){
				printf("0 %d %d\n", l, r);
			}
			else if(k==1){
				printf("1 ");
				solve(l, r);
			}
			else {
				int ans = v[k][lower_bound(v[k].begin(), v[k].end(), l) - v[k].begin()];
				printf("%d %d %d\n", k, ans, ans);
			}
		}
	}
	
	return 0;
}

