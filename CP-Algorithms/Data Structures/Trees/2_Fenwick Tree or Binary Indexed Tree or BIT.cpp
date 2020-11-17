#include <bits/stdc++.h>
using namespace std;


/* Fenwick tree is also called Binary Indexed Tree, or just 
 * BIT abbreviated.
 * 
 * The most common application of Fenwick tree is 
 * calculating the sum of a range in an array
 * 
 * BITs are like a lightweight form of a segment tree. 
*/ 


/// 1 based indexing approach
/// source : geeksforgeeks

// point update range query

const int MAXN = 100009;
int n, arr[MAXN];


int getSum(int BITree[], int idx){
	int sum = 0;
	
	///idx in BITree[] is 1 more than idx in arr[]
	idx = idx + 1;
	
	///traverse ancestors of BITree[idx] 
	while(idx>0){
		sum+=BITree[idx];
		
		idx -= idx&(-idx);  
	}
	
	return sum;
}
	


void updateBIT(int BITree[], int n, int idx, int val){
	idx = idx + 1;
	
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
	
	for(int i=0;i<n;i++){
		updateBIT(BITree, n, i, arr[i]);
	}
	
	return BITree;
}
	


int main(){
	
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &arr[i]);
	
	/// construct BITree
	int *BITree = constructBITree(arr, n);
	
	///Sum of elements in arr[0...5];
	int d = getSum(BITree, 2);
	
	printf("%d\n", d);
	
	///update value in main array
	arr[3] = 10;
	updateBIT(BITree, n, 3, 10);  ///n, idx, updated value 
	
	printf("%d\n", getSum(BITree, 5));
	
	
	return 0;
}

/*
10
5 3 7 8 2 5 8 3 6 8
*/
