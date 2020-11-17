#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;
int n, arr[MAXN];


int getSum(int BITree[], int idx){
	int sum = 0;
	idx = idx + 1;
	while(idx>0){
		sum+=BITree[idx];
		idx -= idx&(-idx);
	}
	return sum;
}

int Sum(int BITree[], int l, int r){
	return (getSum(BITree, r) - getSum(BITree, l-1));
}


void updateBIT(int BITree[], int idx, int val){
	idx = idx + 1;
	while(idx<=n){
		BITree[idx] +=val;
		idx += idx&(-idx);
	}
}


int *constructBITree(int arr[], int n){
	int *BITree = new int[n+1];
	for(int i=1;i<=n;i++){
		BITree[i] = 0;
	}
	for(int i=0;i<n;i++){
		updateBIT(BITree, i, arr[i]);
	}
	return BITree;
}


int main(){
	
	int t, q, x, y, z;
	scanf("%d", &t);
	for(int cs = 1;cs<=t;cs++){ 	
		scanf("%d%d", &n, &q);
		for(int i=0;i<n;i++){
			scanf("%d", &arr[i]);
		}
		
		int *BITree1 = constructBITree(arr, n);
		printf("Case %d:\n",cs);
		while(q--){
			scanf("%d", &x);
			if(x==1){
				scanf("%d", &y);
				printf("%d\n", arr[y]);
				updateBIT(BITree1, y, -arr[y]);
				arr[y] = 0;
			}
			else if(x==2){
				scanf("%d%d", &y, &z);
				updateBIT(BITree1, y, z);
				arr[y]+=z;
			}
			else if(x==3){
				scanf("%d%d", &y, &z);
				int res = Sum(BITree1, y, z);
				printf("%d\n", res);
			}
		}
	}
	
	return 0;
}
