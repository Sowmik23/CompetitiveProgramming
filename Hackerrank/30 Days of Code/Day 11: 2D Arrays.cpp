#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int arr[6][6];
	
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			cin>>arr[i][j];
		}
	}
	
	int mx = -999;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			int k = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
			if(k>mx)mx = k;
		}
	}
	cout<<mx<<endl;
	
	return 0;
}
