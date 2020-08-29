#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	string fName, email;
	vector<string> vec;
	
	regex e(".+@gmail\\.com$");
	
	while(n--){
		cin>>fName;
		cin>>email;
		
		if(regex_match(email, e)){
			vec.push_back(fName);
		}
	}
	
	sort(vec.begin(), vec.end());
	
	for(auto i: vec) cout<<i<<endl;
	
	return 0;
}
