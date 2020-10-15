#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
const ll n = 2e6;
vector<ll> phi(n+2);

struct Array{
	ll idx, value;
} arr[99999979];


bool comp( Array x, Array y){
	if(x.value==y.value) return x.idx<y.idx;
	return (x.value<y.value); 
}


void preCalculate(){
	
	phi[0] = 0;
	phi[1] = 1;
	
	arr[0].idx = 0;
	arr[1].value = 1;
	
	for(ll i=2;i<=n;i++) phi[i] = i;
	
	for(ll i=2;i<=n;i++){
		if(phi[i]==i){
			for(ll j=i;j<=n;j+=i) {
				phi[j] -= phi[j]/i;
				
				arr[j].idx = j;
				arr[j].value = phi[j];
			}
		}
	}
	
	sort(arr, arr+n, comp);
	
	/*for(int i=0;i<50;i++){
		cout<<arr[i].idx<<" "<<arr[i].value<<endl;
	}*/
}


int main(){
	ll k;
	
	preCalculate();
	//cout<<"completed"<<endl;
	cin>>k;
	
	//cout<<arr[n-1].idx<<" "<<arr[n-1].value<<endl;
	
	ll low = 0, high = n, mid;
	
	bool flag = false;
	while(low+1<high){
		mid = (low+high)/2;
		//cout<<mid<<endl;
		if(arr[mid].value==k) {
			cout<<arr[mid].idx-1<<endl;
			flag = true;
			break;
		}
		
		if(arr[mid].value>k) high = mid;
		else low = mid;
	}
	
	//cout<<arr[mid].value<< " "<<arr[mid].idx<<endl;
	if(flag==false and arr[mid].idx!=k) cout<<"0"<<endl;
	
	
	return 0;
}
