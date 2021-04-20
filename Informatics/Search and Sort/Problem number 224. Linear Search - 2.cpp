#include <bits/stdc++.h>

using namespace std;


int main(){
	
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	
	int x;
	bool flag = false;
	scanf("%d", &x);
	for(int i=0;i<n;i++){
		if(arr[i]==x){
			printf("YES\n");
			flag = true;
			break;
		}
	}
	if(flag==false){
		printf("NO\n");
	}
	
	
	return 0;
}

