#include <bits/stdc++.h>
using namespace std;


/// Range update Range query

const int MAXN = 100009;
int n, arr[MAXN];


void updateBIT(int BITree[], int idx, int val){

	idx = idx + 1;
	while(idx<=n){
		BITree[idx] +=val;
		idx += (idx & (-idx));
	}
}

void updateRange(int BITree1[], int BITree2[], int val, int l, int r){
	//update BIT1
	updateBIT(BITree1, l, val);
	updateBIT(BITree1, r+1, -val);
	
	//update BIT2
	updateBIT(BITree2, l, val*(l-1));
	updateBIT(BITree2, r+1, -val*r);
}	


///Returns  sum of arr[0...idx]
int getSum(int BITree[], int idx){
	int sum = 0;
	
	idx = idx+1;
	while(idx>0){
		sum+=BITree[idx];
		
		idx-=idx&(-idx);
	}
	return sum;
}

///Returns the sum of array from [0, x];
int sum(int x, int BITree1[], int BITree2[]){
	return (getSum(BITree1, x)*x) - getSum(BITree2, x);
}


int rangeSum(int l, int r, int BITree1[], int BITree2[]){
	
	///find sum from[0, r] then subtract sum from 
	/// [0, l-1] in order to find sum from [l, r]
	return sum(r, BITree1, BITree2) - sum(l-1, BITree1, BITree2);
}


int *constructBITree(){
	int *BITree = new int[n+1];
	for(int i=1;i<=n;i++){
		BITree[i] =0;
	}
	
	return BITree;
}


int main(){
	
	n = 5;
	//scanf("%d", &n);
	
	//for(int i=0;i<n;i++) scanf("%d", &arr[i]);
	
	int *BITree1, *BITree2;
	
	BITree1 = constructBITree();
	BITree2 = constructBITree();
	
	//// Add 5 to all the elements from [0,4] 
	int l=0, r=4, val=5;
	updateRange(BITree1, BITree2, val, l, r);
	
	l=2, r=4, val=10;
	updateRange(BITree1, BITree2, val, l, r);
	
	//Find sum of all elements from l to r;
	l = 1, r = 4;
	int d = rangeSum(l, r, BITree1, BITree2);
	printf("%d\n", d);
	
	
	return 0;
}
