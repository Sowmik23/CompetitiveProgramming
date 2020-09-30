#include <bits/stdc++.h>
using namespace std;

int primes[100005], nPrime;
vector<bool> mark(100005, true);



void sieve(){
	int n = 100002;
	mark[0] = mark[1] = false;
	for(int i=4;i<n;i+=2) mark[i] = false;
	for(int i=3;i*i<n;i++){
		if(mark[i]){
			for(int j=i*i;j<n;j+=(2*i)){
				mark[j] = false;
			}
		}
	}
	for(int i=2;i<n;i++){
		if(mark[i]) primes[nPrime++] = i;
	}
}



int main(){
	
	sieve();
	//cout<<"finish"<<endl;
	
	int n;
	cin>>n;
	
	if(n>2)  cout<<"2"<<endl;
	else cout<<"1"<<endl;
	
	for(int i=2;i<=n+1;i++){
		if(mark[i]) cout<<"1"<<" ";
		else cout<<"2"<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
