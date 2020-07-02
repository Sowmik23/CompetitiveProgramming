#include <bits/stdc++.h>

using namespace std;


/*
long long find(int x,int y)
{
    if(x>y) return 1;
    long long ans = pow(arr[x],find(x+1,y));
    return ans;
}
*/

int modular(int base, unsigned int exp, unsigned int mod){
	int x = 1;
	int i;
	int power = base%mod;
	
	for(i=0;i<sizeof(int)*8; i++){
		int least_sig_bit = 0x00000001 & (exp>>i);
		if(least_sig_bit) x = (x*power)%mod;
		power = (power*power)%mod;
	}
	
	return x;
}


int main(){
	
	int n;
	cin>>n;
	int arr[n+5];
	for (int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	int q, x, y;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		cin>>x>>y;
		int ans = modular(arr[x],arr[y],100000);
		//cout<<ans<<endl;
		
		if(ans%2==0) cout<<"Even"<<endl;
		else cout<<"Odd"<<endl;
	}
	
	return 0;
}
