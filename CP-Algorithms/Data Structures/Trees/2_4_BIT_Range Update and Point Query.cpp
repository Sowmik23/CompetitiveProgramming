#include <bits/stdc++.h>
using namespace std;

//Range update , point query

const int MAXN = 100009;
int n, arr[MAXN];


void updateBIT(int BITree[], int idx, int val){
	//idx = idx + 1;
	
	while(idx<n){
		BITree[idx] +=val;	
		idx += idx&(-idx);
	}
}


int *constructBITree(){
	int *BITree = new int[n+1];
	for(int i=0;i<n;i++){
		BITree[i] = 0;
	}
	
	for(int i=0;i<n;i++){
		updateBIT(BITree, i, arr[i]);
	}
	
	return BITree;
}

int getSum(int BITree[], int idx){
	int sum = 0;
	//idx = idx + 1;
	
	while(idx>=0){
		sum+=BITree[idx];
		idx-=idx&-idx;
	}
	return sum;
}


void update(int BITree[], int l, int r, int val){
	
	///increase value at 'l' by 'val'
	updateBIT(BITree, l, val);

	///decrease value at 'r+1' by 'val'
	updateBIT(BITree, r+1, -val);
}



int main(){
	
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &arr[i]);
	
	int *BITree = constructBITree();
	
	cout<<getSum(BITree, 4)<<endl;
	int l=2, r = 4, val = 2;
	update(BITree, l, r, val);
	
	int idx = 4;
	cout<<getSum(BITree, idx)<<endl; 
	
	
	return 0;
}
