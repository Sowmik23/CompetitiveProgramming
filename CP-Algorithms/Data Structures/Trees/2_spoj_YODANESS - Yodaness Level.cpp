#include <bits/stdc++.h>
using namespace std;

/// Counting Inversion problem
/// Solved with : BIT/Fenwick Tree

const int MAXN = 3e4+9;
int n, BITree[MAXN];


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
		BITree[idx]+=val;
		idx+=idx&(-idx);
	}
}


int main(){
	
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int arr[n+6];
		map<string, int> mp;
		mp.clear();
		string str[n+6], str2;
		for(int i=0;i<n;i++){
			cin>>str[i];
		}
		
		
		for(int i=1;i<=n;i++){
			cin>>str2;
			mp[str2] = i;
		}
		
		for(int i=0;i<n;i++){
			arr[i] = mp[str[i]];
		}
		memset(BITree, 0, sizeof(BITree));
		
		int sum = 0;
		for(int i=n-1;i>=0;i--){
			sum+= getSum(arr[i]);
			
			updateBIT(arr[i], 1);
		}
		
		printf("%d\n", sum);
	}
	
	
	return 0;
}
