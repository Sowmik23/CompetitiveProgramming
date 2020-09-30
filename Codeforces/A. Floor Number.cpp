#include <bits/stdc++.h>
using namespace std;


int main(){
	int t;
	int n, x;
	cin>>t;
	while(t--){
		cin>>n>>x;
		
		if(n==1 or n==2) cout<<1<<endl;
		else {
			int low;
			int high = 2;
			int flr=1;
			while(1) {
				low = high + 1; 
				high = low+x-1;
				flr++;
				if(n>=low and n<=high){
					cout<<flr<<endl;
					break;
				}
				
			}
		}
			
	}
	
	return 0;
}
