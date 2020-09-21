#include <bits/stdc++.h>
using namespace std;

#define ll long long 


int main(){
	
	int x;
	int arr[12];
	int sum=0;
	for(int i=0;i<10;i++){
		cin>>x;
		arr[i] = x;
		sum+=x;
		
		if(sum>=100){
			if(sum-100 <= 100 - (sum-arr[i])) cout<<sum<<endl;
			else cout<<sum-arr[i]<<endl;
			return 0;
		}
	}
	cout<<sum<<endl;
	
	return 0;
}







