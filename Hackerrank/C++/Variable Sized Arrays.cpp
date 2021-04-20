#include <bits/stdc++.h>
using namespace std;


////very interesting problem

int main(){
	
	int n, q, k, a, b;
	scanf("%d%d", &n, &q);
	//int arr[100009][300009]; ///using array is uneffecient so use vector
	vector<vector<int>> v(n);
	
	for(int i=0;i<n;i++){
		scanf("%d", &k);
		v[i].resize(k);
		for(int j=0;j<k;j++){
			scanf("%d", &v[i][j]);
		}
	}
	while(q--){
		scanf("%d%d", &a, &b);
		
		printf("%d\n", v[a][b]);
	}
	
	
	return 0;
}
