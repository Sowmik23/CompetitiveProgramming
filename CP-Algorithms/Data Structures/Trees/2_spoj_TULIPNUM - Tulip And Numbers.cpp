#include <bits/stdc++.h>
using namespace std;

/// Find the number of distinct element in a sub-array
/// BIT or Fenwick Tree


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
	return  getSum(r); // - getSum(l);
}
 
 
void updateBIT(int idx, int val){
	while(idx<=n){
		BITree[idx] +=val;
		idx+=idx&(-idx);
	}
}	


int main(){
	
	//ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	int t, q, x, y;
	scanf("%d", &t);
	for(int cs=1;cs<=t;cs++) {
		memset(arr, 0, sizeof(arr));
		memset(BITree, 0, sizeof(BITree));
		
		scanf("%d%d", &n, &q);
		scanf("%d", &x);
		
		//updateBIT(1, 0);
		arr[0] = 0;
		for(int i=1;i<n;i++){
			scanf("%d", &y);
			if(y!=x) {
				arr[i] = arr[i-1] + 1;
				//updateBIT(i+1, arr[i]);
			}
			else {
				arr[i] = arr[i-1];
				//updateBIT(i+1, arr[i]);
			}
			x = y;
		} 
		
		//for(int i=0;i<n;i++) cout<<arr[i]<<" ";
		//cout<<endl;
		
		int l, r;		
	
		printf("Case %d:\n", cs);
		for(int i=0;i<q;i++){
			scanf("%d%d", &l, &r);
			
			printf("%d\n", arr[r-1] - arr[l-1] + 1);
		}
	
	}	
	
	return 0;
}

