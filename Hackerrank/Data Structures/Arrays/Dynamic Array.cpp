#include <bits/stdc++.h>
using namespace std;

//vector within a vector
// seq[0] = [5, 3]
//seq[1] = [7]

int main(){
	
	int n,q, z;
	cin>>n>>q;
	int x, y, lastAnswer = 0;
	
	vector<vector<int>> seqlist;
	vector<int> seq;
	
	for(int i=0;i<n;i++){
		seqlist.push_back(seq);
	}
	
	while(q--){
		cin>>z>>x>>y;
		
		int idx = (x^lastAnswer)%n;
		//cout<<idx<<endl;
		
		if(z==1){
			seqlist[idx].push_back(y);
		}
		else if(z==2){
			int k = y%seqlist[idx].size();
			lastAnswer = seqlist[idx].at(k);
			cout<<lastAnswer<<endl;
		}
	}
	
	return 0;
}
