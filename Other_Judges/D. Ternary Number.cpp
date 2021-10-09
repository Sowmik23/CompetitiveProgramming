#include <bits/stdc++.h>
using namespace std;


long long cnt(long long  i, long long n, vector<long long> &dp){
	if(dp[i]!=0) return dp[i];
	if(i>n) return 0;
	
	long long c = 1+cnt(i*10, n, dp) + cnt(i*10+1, n, dp) + cnt(i*10+2, n, dp);
	dp[i] = c;
	return c;
}


int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n;
		scanf("%d",&n);
		
		//vector<long long> dp(n, 0);
		
		//printf("%lld\n", 1+cnt(1, n, dp));
	
		
		int len = log10(n)+1;
		int ans = 0, cnt = 0;
		
		if(n==0) ans = 1;
		else if(n==1) ans = 2;
		else if(n==2) ans = 3;
		else {
			if(len>=2){
				if(len==2) ans = 3;
				else if(len==3) ans = 9;
				else if(len==4) ans =  18;
				else if(len ==4) ans = 27;
				else if(len==5) ans =  36;
				else if(len==6) ans = 45;
				else if(len==7) ans = 54;
				else if(len==8) ans = 63;
				else if(len==9) ans = 72;
				else if(len==10) ans = 81;
				else if(len==11) ans = 90;
				else if(len==12) ans = 99;
				else if(len==13) ans = 108;
				else if(len==14) ans = 117;
				else if(len==15) ans = 126;
				
				 int a = n%10;
				 n/=10;
				 a+= 10*(n%10);
				 if(a==0) cnt = 1;
				 else if(a==1) cnt = 2;
				 else if(a==2) cnt = 3;

				 if(a<11) cnt+=1;
				 else if(a<12) cnt+=2;
				 else if(a<20) cnt+=3;
				 else if(a<21) cnt+=4;
				 else if(a<22) cnt+=5;
				 else if(a<23) cnt+=6;
			 }
		 }
		 
		 cout<<ans<<endl;
	
	} 
	
	
	return 0;
}
