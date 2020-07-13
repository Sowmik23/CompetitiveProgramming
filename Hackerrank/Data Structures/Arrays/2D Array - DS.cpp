#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int arr[10][10];
	
	for (int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			cin>>arr[i][j];
		}
	}
	
	int sum = 0, res=-64;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
			if(sum>res) res = sum;
		}
	}
	cout<<res<<endl;
	
	return 0;
}
