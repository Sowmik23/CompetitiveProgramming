#include <bits/stdc++.h>
using namespace std;


///Time Complexity: O(n*m)
/// n = str.size()
/// m = pattern.size()


bool hasSubstring(string str, string pattern){
	int i = 0, j = 0, k = 0;
	
	while(i<str.size() and j<pattern.size()){
		if(str[i]==pattern[j]){
			i++;
			j++;
		}
		else {
			j = 0;
			k++;
			i = k;
		}
	}
	if(j==pattern.size()) {
		cout<<i-j<<" is the start matching index"<<endl;
		return true;
	}
	return false;
}


int main(){
	
	string str = "abcbcglx";
	string pattern = "bcgl";
	
	if(hasSubstring(str, pattern)) cout<<pattern<<" is a substring of "<<str<<endl;
	else cout<<"No, it is not a substring"<<endl;
	
	
	return 0;
}
