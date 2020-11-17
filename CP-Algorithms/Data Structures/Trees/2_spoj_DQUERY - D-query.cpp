#include <bits/stdc++.h>
using namespace std;

/// Find the number of distinct element in a sub-array
/// BIT or Fenwick Tree

typedef long long ll;
const int MAXN = 4e6+9;
int n, arr[MAXN], BITree[MAXN];
ll last_visit[MAXN];


struct Query {
	int l, r, idx;
};


bool cmp(Query x, Query y){
	return x.r < y.r;
}


int getSum(int idx){
	int sum = 0;
	while(idx>0){
		sum+=BITree[idx];
		idx-=idx&(-idx);
	}
	return sum;
}

void updateBIT(int idx, int val){
	while(idx<=n){
		BITree[idx] +=val;
		idx+=idx&(-idx);
	}
}



void ansQueries(Query queries[], int q) {
	
	memset(BITree, 0, sizeof(BITree));
	memset(last_visit, -1, sizeof(last_visit));
	
	int j =0;
	int ans[q+5];
	for(int i=0;i<n;i++){
		if(arr[i]<MAXN and last_visit[arr[i]]!=-1){
			ll x = last_visit[arr[i]] + 1;
			if(x<=n) updateBIT(x, -1);
		}
		
		if(arr[i]<MAXN) {
			last_visit[arr[i]] = i;
			updateBIT(i+1, 1);
		}
		
		while(j<q and queries[j].r==i){
			ans[queries[j].idx] = getSum(queries[j].r+1) - getSum(queries[j].l);
			j++;
		}
	}
	for(int i=0;i<q;i++){
		printf("%d\n", ans[i]);
	}
}
	


int main(){
	
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	int q;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	
	int l, r;
	scanf("%d", &q);
	
	Query queries[q+4];
	
	for(int i=0;i<q;i++){
		scanf("%d%d", &l, &r);
		queries[i].l = l-1;
		queries[i].r = r-1;
		queries[i].idx = i;
	}
	
	sort(queries, queries+q, cmp);		
	
	ansQueries(queries, q);
	
	
	return 0;
}
