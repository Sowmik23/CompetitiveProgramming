#include <bits/stdc++.h>
using namespace std;


/// Counting number of Inversion in an array using 
/// Fenwick Tree / Binary Indexed Tree

typedef long long ll;
const int MAXN = 2e5+9;
ll n, arr[MAXN], tmp[MAXN], BITree[MAXN];


ll getSum(int idx){
	int sum =0;
	while(idx>0){
		sum+=BITree[idx];
		idx-=idx&(-idx);
	}
	return sum;
}


void updateBIT(int idx, ll val){
	while(idx<=n){
		BITree[idx] +=val;
		idx+=idx&(-idx);
	}
}

/*
void convert(){
	for(int i=0;i<n;i++){
		tmp[i] = arr[i];
	}
	sort(tmp, tmp+n);
	
	for(int i=0;i<n;i++){
		int pos = lower_bound(tmp, tmp+n, arr[i]) - tmp;
		arr[i] = pos+1;
	}
}*/

/*
void getInvCount(){
	ll cnt = 0;
	
	convert();
	
	memset(BITree, 0, sizeof(BITree));
	
	for(int i=n-1;i>=0;i--){
		cnt+= getSum(arr[i]-1);
		
		updateBIT(arr[i], 1);
	}
	
	printf("%lld\n", cnt);
}*/
	
	

int main(){
	
	int t;
	scanf("%d", &t);
	while(t--) {
		memset(arr, 0, sizeof(arr));
		memset(tmp, 0, sizeof(tmp));
		memset(BITree, 0, sizeof(BITree));

		scanf("%lld", &n);
		for(int i=0;i<n;i++){
			scanf("%lld", &arr[i]);
			tmp[i] = arr[i];
		}
		
		
		//getInvCount();
		ll cnt = 0;
	
		//convert();
		/*for(int i=0;i<n;i++){
			tmp[i] = arr[i];
		}*/
		sort(tmp, tmp+n);
		
		for(int i=0;i<n;i++){
			int pos = lower_bound(tmp, tmp+n, arr[i]) - tmp;
			arr[i] = pos+1;
		}
		
		
		
		for(int i=n-1;i>=0;i--){
			cnt+= getSum(arr[i]-1);
			
			updateBIT(arr[i], 1);
		}
		
		printf("%lld\n", cnt);
	}

	
	return 0;
}
