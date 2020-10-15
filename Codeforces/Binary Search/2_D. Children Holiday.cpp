#include <bits/stdc++.h>
using namespace std;

struct System {
	int time, total, rests;
	int res;
} arr[1005];


int m, n;

bool good(int time){
	int sum=0;
	for(int i=0;i<n;i++){
		int NoOfBallons = time/(arr[i].time*arr[i].rests + arr[i].total)*arr[i].rests + min( (time%(arr[i].time*arr[i].rests + arr[i].total)/arr[i].time), arr[i].rests);
		arr[i].res = NoOfBallons;
		sum+=NoOfBallons;
	}
	return sum>=m;
}


int main(){
	int x, y, z;
	
	cin>>m>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y>>z;
		arr[i].time =x;
		arr[i].total = y;
		arr[i].rests = z;
	} 
	
	
	
	
	int low = 0, high = 1e9, mid;
	
	while(low+1<high){
		mid = (low+high)/2;
		
		if(good(mid)) high = mid;
		else low =mid;
	}
	//cout<<low<<" "<<mid<<" "<<high<<endl;
	cout<<high<<endl;
	for(int i=0;i<n;i++) cout<<arr[i].res<<" ";
	
	
	return 0;
}
