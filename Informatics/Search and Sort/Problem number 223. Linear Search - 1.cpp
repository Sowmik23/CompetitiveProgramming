#include <bits/stdc++.h>

using namespace std;


int main(){
	
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	
	int x, cnt=0;
	scanf("%d", &x);
	for(int i=0;i<n;i++){
		if(arr[i]==x){
			cnt++;
		}
	}
	printf("%d\n", cnt);
	
	return 0;
}
