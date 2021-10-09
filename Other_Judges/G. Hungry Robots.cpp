#include <bits/stdc++.h>
using namespace std;


int main(){
	
	int t;
	scanf("%d" , &t);
	
	for(int tt=0;tt<t;tt++){
		long long n;
		scanf("%lld" , &n);
		
		long long robot[n+1], power[n+1];
		
		for(int i=0;i<n;i++){
			scanf("%lld" , &robot[i]);
		}
		
		for(int i=0;i<n;i++){
			scanf("%lld" , &power[i]);
		}
		
		bool flag = false;
		
		for(int i=0;i<n;i++){
			if(robot[i]<=power[i]){
				power[i] -=robot[i];
				robot[i] = 0;
			}
			else {
				robot[i]-=power[i];
				
				if(i!=0){
					if(power[i-1]>=robot[i]){
						power[i-1] -=robot[i];
						robot[i] = 0;
					}
					else {
						flag = true;
						//cout<<"NO"<<endl;
						//break;
					}
				}
				else {
					if(power[n-1]>=robot[i]){
						power[n-1]-=robot[i];
						robot[i] = 0;
					}
					else {
						flag = true;
						//cout<<"NO"<<endl;
						//break;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			//cout<<robot[i]<<" ";
			if(robot[i]!=0) {
				flag = true;
				cout<<"NO"<<endl;
				break;
			}
		}
		//cout<<endl;
		if(flag==false) cout<<"YES"<<endl;
		
	}
	
	return 0;
}
