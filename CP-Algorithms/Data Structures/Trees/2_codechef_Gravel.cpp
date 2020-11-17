#include <bits/stdc++.h>
using namespace std;


///Range update point query

typedef long long ll;
const int MAXN = 1e6+5;
ll n;
ll BITree[MAXN];


ll getSum(int idx){
	ll sum =0;
	while(idx>0){
		sum+=BITree[idx];
		idx-=idx&(-idx);
	}
	return sum;
}

void updateBIT(int idx, ll val){
	while(idx<=n){
		BITree[idx]+=val;
		idx+=idx&(-idx);
	}
}


void updateRange(int l, int r, int val){
	updateBIT(l, val);
	updateBIT(r+1, -val);
}

/*
void constructBITree(ll val){

	for(int i=0;i<=n+1;i++){
		BITree[i] = 0;
	}
	
	for(int i=1;i<=n;i++){
		updateBIT(i, val);
	}
}
*/

int main(){
	
	///without this line it gives time limit exit ;(
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	ll m, c, u, v, k, p;
	char str[2];
	scanf("%lld%lld%lld", &n, &m, &c);
	
	//constructBITree(c);
	updateRange(1, n, c);
	for(int t=1;t<=m;t++) {
		scanf("%s", str);
		//cin>>str;
		
		if(str[0]=='S'){
			scanf("%lld%lld%lld", &u, &v, &k);
			updateRange(u, v, k);
		}
		else if(str[0]=='Q'){
			scanf("%lld", &p);
			printf("%lld\n", getSum(p));
		}
	}
	
	return 0;
}

/*
7 5 0
Q 7
S 1 7 1
Q 3
S 1 3 1
Q 3
*/
