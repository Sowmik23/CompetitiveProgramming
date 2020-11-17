#include <bits/stdc++.h>
using namespace std;

/// Point update range queries---->
///Fenwick Tree/Binary Indexed Tree

const int MAXN = 200009;
int n, arr[MAXN];


int getSum(int BITree[], int idx){
	int sum = 0;
	
	///idx in BITree[] is 1 more than idx in arr[]
	//idx = idx + 1;
	
	///traverse ancestors of BITree[idx] 
	while(idx>0){
		sum+=BITree[idx];
		
		idx -= idx&(-idx);  
	}
	
	return sum;
}

int Sum(int BITree[], int l, int r){
	return (getSum(BITree, r) - getSum(BITree, l-1));
}	


void updateBIT(int BITree[], int n, int idx, int val){
	//idx = idx + 1;
	///traverse all ancestors and add val
	while(idx<=n){
		BITree[idx] += val;
		
		///update idx of the parent
		idx += idx&(-idx);  
	}
}


int *constructBITree(int arr[], int n){
	int *BITree = new int[n+1];
	
	///initialize BITree as 0
	for(int i=1;i<=n;i++){
		BITree[i] = 0;
	}
	
	for(int i=1;i<=n;i++){
		updateBIT(BITree, n, i, arr[i]);
	}
	
	return BITree;
}



int main(){
	
	int x, y;
	
	for(int cs=1; ;cs++) {
		scanf("%d", &n);
		if(n!=0 and cs!=1) printf("\n");
		if(n==0) break;
		
		printf("Case %d:\n", cs);
		for(int i=1;i<=n;i++){
			scanf("%d", &arr[i]);
		}
		int *BITree1;
		BITree1 = constructBITree(arr, n);
		
		char str[5];
		
		while(1) {
			scanf("%s", str);
			if(str[0]=='E') break;
			
			scanf("%d%d", &x, &y);
			if(str[0]=='M'){
				int d = Sum(BITree1, x, y);
				printf("%d\n", d);
			}
			else if(str[0]=='S'){
				updateBIT(BITree1, n, x, y-arr[x]);
				arr[x] = y;
			}
		}
		//printf("\n");
	}
		
	return 0;
}

/*
 * Test case:
3
100
100
100
M 1 1
M 1 3
S 2 200
M 1 2
S 3 0
M 2 3
END
10
1
2
3
4
5
6
7
8
9
10
M 1 10
END
0
*/
