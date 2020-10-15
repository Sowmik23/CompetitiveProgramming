#include <bits/stdc++.h>
using namespace std;


/// Interesting problem :0)
/// Problem: https://codeforces.com/problemset/problem/906/D
/// Mark as ToDo

int arr[100009];


int getPhi(int x){
	static map<int, int> mp;
	
	if(mp[x]) return mp[x];
	int res = x, tmp = x;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			while(x%i==0) x/=i;
			res -= res/i;
		}
	}
	if(x>1) res -= res/x;
	return mp[tmp] = res;
}
 


int f(long long x, int y) {
	if(x<y) {
		return x;
	}
	else return x%y + y;
}


int ksm(int x, int k, int mod){
	int ret = 1 , tmp = x;
	
	while(k){
		if(k&1) ret = f(1LL*ret*tmp, mod);
		tmp = f(1LL*tmp*tmp, mod);
		k>>=1;
	}
	return ret;
}


int solve(int l, int r, int mod){
	if(getPhi(mod)==1 or l==r) return f(arr[l], mod);
	
	return ksm(arr[l], solve(l+1, r, getPhi(mod)), mod);
}


int main(){
	
	int n, m, q, l, r;
	
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	
	scanf("%d",&q);
	while(q--){
		scanf("%d%d", &l, &r);
		
		printf("%d\n", solve(l, r, m)%m);
		cout<<"Marked as wrong ans"<<endl;
	}
	
	
	return 0;
}
