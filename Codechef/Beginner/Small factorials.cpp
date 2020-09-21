#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

///It can find upto 100! 



int main() {
	int t;
	cin>>t;
	int n;
	int arr[200];
	
	while(t--){
	    cin>>n;
	   	
	   	int m, tmp, j;
		arr[0] = 1;
		m = 1;	
		
		for(int i=2;i<=n;i++){
			tmp = 0;
			for(j=0;j<m;j++){
				arr[j] = arr[j]*i + tmp;
				tmp = arr[j]/10;
				arr[j] = arr[j]%10;
			}
			while(tmp){
				arr[j] = tmp%10;
				j++;
				m++;
				tmp = tmp/10;
			} 
		}
		for(int i=m-1;i>=0;i--){
			cout<<arr[i];
		}
		cout<<endl;
	}
	
	return 0;
}
