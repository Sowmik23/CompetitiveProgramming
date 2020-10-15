#include <bits/stdc++.h>
using namespace std;


/// Problem: https://codeforces.com/contest/154/problem/B
/// Nice problem keep a look

int primes[100005], nPrime;
vector<bool> mark(100009, false);
vector<int> store[100005];
int cnt[100005];
set<int> st[100005];


void sieve(){
	int n= 100005;
	
	for(int i=2;i<n;i++){
		if(mark[i]==false) {
			for(int j=i;j<n;j+=i){
				mark[j] = true;
				store[j].push_back(i);
			}
		}
	}
}


void add(int x) {
	for(auto i: store[x]){
		if(st[i].size()){
			cout<<"Conflict with "<<*st[i].begin()<<endl;
			return ;
		}
	}
	for(auto i: store[x]) {
		st[i].insert(x);
	}
	cnt[x]++;
	cout<<"Success"<<endl;
}


void del(int x) {
	for(auto i: store[x]){
		st[i].erase(x);
	}
	cout<<"Success"<<endl;
	cnt[x]--;
}



int main(){
	
	sieve();
	//cout<<"finish"<<endl;
	
	
	int n, m, x;
	cin>>n>>m;
	char sign;
	
	while(m--){
		cin>>sign;
		cin>>x;
		//cout<<sign<<" "<<x<<endl;
	
		if(sign=='+') {
			if(cnt[x]) {
				cout<<"Already on"<<endl;
				continue;
			}
			add(x);
		}
		else if(sign=='-') {		
			if(cnt[x]==0){
				cout<<"Already off"<<endl;
				continue;
			}
			del(x);
		}
	}
	
	return 0;
}
