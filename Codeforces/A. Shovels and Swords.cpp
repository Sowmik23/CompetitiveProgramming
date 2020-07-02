#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	long long a, b, ans, res;
	
	cin>>t;
	while(t--){
		cin>>a>>b;
		
		ans = (a+b)/3;
		ans = min(a, ans);
		ans = min(ans, b);
		/*if(a==0 or b==0) ans = 0;
		else if(a>=b){
			res = a/2;
			if(res<=b){
				int k = b - res;
				int d = a - res;
				if(d==1 and k==2) res++;
				else if(k>=3) {
					res--;
					k-=4;
					res+=2;
				}
				ans = res;
			}
			else if(res>b){
				ans = b;
			}
		}
		else {
			res = b/2;
			if(res<=a){
				int k = a - res;
				int d = b - res;
				if(d==1 and k==2) res++;
				if(k>=3) {
					res--;
					k-=4;
					res+=2;
				}
				ans = res;
			}
			else if(res>a){
				ans = a;
			}
		} */
		
		cout<<ans<<endl;
	}
	
	
	
	return 0;
}
