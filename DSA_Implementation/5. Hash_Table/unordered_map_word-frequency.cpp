#include <bits/stdc++.h>
using namespace std;


void countFrequency(string str){
	unordered_map<string, int> umap;
	unordered_map<string, int>:: iterator it;

	stringstream ss(str);
	string word;
	while(ss>>word){
		umap[word]++;
	}

	for(it = umap.begin();it!=umap.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
}


int main(){
	
	string str;
	getline(cin, str);
	//cout<<str<<endl;
	countFrequency(str);
	
	return 0;
}
