#include <bits/stdc++.h>
using namespace std;

/*
 * 1. FindSet(x): O(alpha(n))
 * 2. UniteSets(x, y): O(alpha(n))
 * 3. MakeSet(x): O(1)
 * 4. Disunion(list): O(n)
 */


const int MAXN = 100009;
int arr[MAXN], rnk[MAXN], rm[MAXN];
int n;

int Find(int x){
	if(arr[x] ==x) return x;
	return arr[x] = Find(x);
}

void Union(int x, int y){
	int p1 = Find(x);
	int p2 = Find(y);
	
	if(rnk[p1]>rnk[p2]) {
		arr[p2] = p1;
		rnk[p1] = rnk[p2]+1;
	}
	else {
		arr[p1] = p2;
		rnk[p2] = max(rnk[p2], rnk[p1] + 1);
	}
}


void disUnion(int nroot){
	int p;
	for(int i=0;i<n;i++) Find(i);
	for(int i=0;i<n;i++){
		p = Find(i);
		if(rm[p] and !rm[i]) {
			arr[p] = i;
			arr[i] = i;
		}
	}
	for(int i=0;i<n;i++) Find(i);
	for(int i=0;i<n;i++){
		if(rm[i]){
			arr[i] = nroot;
			rm[i] = 0;
		}
	}
	
	memset(rnk, 0, sizeof(rnk));
	for(int i=0;i<n;i++){
		p = Find(i);
		if(p!=i) rnk[p] = 1;
	}
}


int main(){
	
	scanf("%d", &n);
	
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	
	
	return 0;
}
