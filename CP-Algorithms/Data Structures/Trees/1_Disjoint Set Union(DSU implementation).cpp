#include <bits/stdc++.h>
using namespace std;



const int MAXN = 100009;
int n, arr[MAXN], num[MAXN];

void make_set(int n){
	for(int i=0;i<=n;i++){
		arr[i] = i;
		num[i] = 0;
	}
}


int Find(int x){
	if(x==arr[x]) return x;
	else return arr[x] = Find(arr[x]);
}


void Union(int x, int y){
	int xroot = Find(x);
	int yroot = Find(y);
	
	if(num[xroot]>num[yroot]) arr[yroot] = xroot;
	else {
		arr[xroot] = yroot;
		if(num[xroot] == num[yroot]) num[yroot]++;
	}
}


bool isConnected(int x, int y){
	if(Find(x) == Find(y)) return true;
	else return false;
}



int main(){
	
	int m, a, b;
	scanf("%d%d", &n, &m);
	
	make_set(n);
	
	while(m--) {
		scanf("%d%d", &a, &b);
		
		Union(a, b);
	}
	
	int q, x, y;
	scanf("%d", &q);
	int cnt =0;
	while(q--){
		scanf("%d%d", &x, &y);
			
		if(isConnected(x, y)) cnt++;
	}
	printf("%d\n", cnt);
	
		
	return 0;
}
