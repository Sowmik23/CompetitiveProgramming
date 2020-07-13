#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, d;
	cin>>n>>d;
	
	int arr[n], brr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	//cout<<"sesh"<<endl;
	int j=0;
	for(int i=d;i<(n+d);i++){
		//cout<<i%n<<" "<<arr[i%n]<<endl;
		brr[j++] = arr[i%n];
	}
	for(int i=0;i<n;i++) cout<<brr[i]<<" ";
	cout<<endl;
	
	return 0;
}
