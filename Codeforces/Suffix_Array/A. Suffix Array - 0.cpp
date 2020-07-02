//TLE in test case 26 
//Complexity: O(n^2logn)


#include <bits/stdc++.h>

using namespace std;

int main(){
	
	string str;
	cin>>str;
	
	int len = str.length();
	int n = len;
	
	map<string, int> mp;
	
	for(int i=0;i<len;i++){
		
		//cout<<str.substr(i, n)<<endl;
		mp.insert(pair<string, int>(str.substr(i,n), i));
		n--;
	}
	
	cout<<len<<" ";
	
	for(auto i : mp){
		cout<<i.second<<" ";
	}
	cout<<endl;
	
	return 0;
}
