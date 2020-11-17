#include <bits/stdc++.h>
using namespace std;

//Unsolved---------------->


/// Finding unique elements in a subarray[l....r]

/// Binary Indexed Tree/ Fenwick Tree



typedef long long ll;
 
const int MAXN = 1e5+9;
int n, arr[MAXN], BITree[MAXN], last_visit[MAXN];
 
 
int getSum(int idx){
	int sum = 0;
	while(idx>0){
		sum+=BITree[idx];
		idx-=idx&(-idx);
	}
	return sum;
}
 
 
int getResult(int l, int r){
	return  getSum(r+1) - getSum(l);
}
 
 
void updateBIT(int idx, int val){
	while(idx<=n){
		BITree[idx] +=val;
		idx+=idx&(-idx);
	}
}
 
 
void constructBITree(){
	
	memset(BITree, 0, sizeof(BITree));
	memset(last_visit, -1, sizeof(last_visit));
	
	for(int i=0;i<n;i++){
		if(last_visit[arr[i]]!=-1){
			updateBIT(last_visit[arr[i]] + 1, -1);
		}
		
		last_visit[arr[i]] = i;
		updateBIT(i+1, 1);
	}
}

int main(){
	
	int q, x, idx, val, l, r;
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		scanf("%d", &arr[i]);
	}
	
	constructBITree();
	
	scanf("%d", &q);
	while(q--){
		scanf("%d", &x);
		if(x==1){
			scanf("%d%d", &idx, &val);
			updateBIT(idx+1, val);
		}
		else if(x==2){
			scanf("%d%d", &l, &r);
			
			printf("%d\n", getResult(l, r));
		}
	}
	
	return 0;
}
