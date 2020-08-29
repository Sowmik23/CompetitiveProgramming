#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	int n_ofSwaps = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(arr[j]>arr[j+1]){
				n_ofSwaps++;
				swap(arr[j], arr[j+1]);
			}
		}
	}
	//for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	
	cout<<"Array is sorted in "<<n_ofSwaps<<" swaps."<<endl;
	cout<<"First Element: "<<arr[0]<<endl;
	cout<<"Last Element: "<<arr[n-1]<<endl;
	
	return 0;
}
