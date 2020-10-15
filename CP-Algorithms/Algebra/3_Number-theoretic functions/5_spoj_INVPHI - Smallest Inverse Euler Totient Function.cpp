#include <bits/stdc++.h>
using namespace std;


/// Remember: for this problem phi[i] = n  and max n = 1e8
/// so make sure your mx will larger than 1e8

const int mx = 203000000;


int phi[mx], minValue[mx];

void GeneratePhiAccordingtoProblem(){
	
	for(int i=1;i<mx;i++) phi[i] = i;

	for(int i=2;i<mx;i++){
		if(phi[i]==i){
			for(int j=i;j<mx;j+=i){
				phi[j] -= phi[j]/i;
			}
		}
	}
	
	//Here is the main tricks
	for(int i=1;i<mx;i++){
		if(phi[i]<=100000000 and minValue[phi[i]]==0){
			minValue[phi[i]] = i;
		}
	}
}



int main(){
	
	GeneratePhiAccordingtoProblem();
	//cout<<"finished"<<endl;
	
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d",&n);
		
		if(minValue[n]) printf("%d\n", minValue[n]);
		else printf("-1\n");
	}
	
	return 0;
}
