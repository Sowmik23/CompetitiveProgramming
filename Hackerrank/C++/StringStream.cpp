#include <bits/stdc++.h>

using namespace std;



vector<int> parseInts(string str){
	int tmp;
	char ch;
	vector<int> res;
	stringstream ss(str);
	
	while(ss>>tmp){
		res.push_back(tmp);
		ss>>ch;
	}
	return res;
}


int main(){
	
	string str;
	cin>>str;
	vector<int> integers = parseInts(str);
	
	for(int i=0;i<integers.size();i++){
		cout<<integers[i]<<endl;
	}
	
	
	return 0;
}
