#include <bits/stdc++.h>
using namespace std;

int main(){

	int t, n;
	scanf("%d", &t);
	for(int i=1;i<=t;i++){
		scanf("%d", &n);
		
		int res = ceil(log2(n+1));
		
		printf("Case %d: %d\n", i, res);
	}

	return 0;
}
