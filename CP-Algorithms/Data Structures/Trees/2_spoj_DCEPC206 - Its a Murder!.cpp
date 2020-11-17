#include <bits/stdc++.h>
using namespace std;

// Simple counting inversions problem
// Solved with BInary Indexed Tree/Fenwick Tree
/// optimized BIT


typedef long long ll;
const int MAXN = 1e5+9;
ll n, BITree[MAXN];

ll getSum(int idx){
	ll sum = 0;
	while(idx>0){
		sum+=BITree[idx];
		idx-=idx&(-idx);
	}
	return sum;
}

void updateBIT(int idx, int val) {
	while(idx<=n){
		BITree[idx]+=val;
		idx+=idx&(-idx);
	}
}


int main(){
	
	int t;
	scanf("%d", &t);
	while(t--){
		memset(BITree, 0, sizeof(BITree));
		
		scanf("%lld", &n);
		int arr[n+5], tmp[n+5];
		for(int i=0;i<n;i++) {
			scanf("%d", &arr[i]);
			tmp[i] = arr[i];
		}
		
		sort(tmp, tmp+n);
		
		for(int i=0;i<n;i++){
			int pos = lower_bound(tmp, tmp+n, arr[i]) - tmp;
			arr[i] = pos;
		}
		
		ll sum =0;
		for(int i=0;i<n;i++){
			sum+=getSum(arr[i]);
			
			updateBIT(arr[i]+1, tmp[arr[i]]);
		}
		
		printf("%lld\n", sum);
	}
	
	
	return 0;
}
