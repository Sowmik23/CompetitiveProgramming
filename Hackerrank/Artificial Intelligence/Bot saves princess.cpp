#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	string str[n];
	
	for(int i=0;i<n;i++) cin>>str[i];
	
	int a, b;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(str[i][j]=='p'){
				a = i;
				b = j;
			}
		}
	}
	//cout<<a<<" "<<b<<endl;
	int x = n/2;
	int y = x;
	
	int pos1 = x - a;
	int pos2 = y - b;
	
	if(pos1>0){
		while(pos1--) cout<<"UP"<<endl;
	}
	else if(pos1<0){
		while(pos1++) cout<<"DOWN"<<endl;
	}
	
	if(pos2>0) {
		while(pos2--) cout<<"LEFT"<<endl; 
	}
	else if(pos2<0) {
		while(pos2++) cout<<"RIGHT"<<endl;
	}
	
	return 0;
}
