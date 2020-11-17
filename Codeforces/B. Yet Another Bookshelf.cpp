#include <bits/stdc++.h>
using namespace std;


int main(){
	
	int t, n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int arr[n+3];
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		
		int flag = 0, mx = -1, cnt=0;
		for(int i=0;i<n;i++){
			if(arr[i]==1){
				flag = 1;
				mx = max(i, mx);
			}
			if(flag==1 and arr[i]==0){
				cnt++;
			}
		}
		cout<<cnt-(n-mx-1)<<endl; //<<" "<<mx<<" "<<cnt<<endl;
		
	}
	
	return 0;
}
