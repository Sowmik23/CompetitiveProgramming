#include <bits/stdc++.h>
using namespace std;

int main(){
	
	double total_event = 6*6;
	int cnt = 0;	
	for(int i=1;i<=6;i++){
		for(int j=1;j<=6;j++){
			if(i+j<=9) cnt++;
		}
	}
	
	double probability = cnt/total_event;
	cout<<probability<<endl;
	
	return 0;
}
