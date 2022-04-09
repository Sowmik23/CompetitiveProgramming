#include <bits/stdc++.h>
using namespace std;


class SubstringSearch {
	
public:
	bool KMP(string str, string pattern){
		
		vector<int> prefixValues = prefixFunction(pattern);
		
		int i = 0, j = 0;
		
		while(i<str.size() and j<pattern.size()){
			if(str[i]==pattern[j]){
				i++;
				j++;
			}
			else {
				if(j!=0){
					j = prefixValues[j-1];
				}
				else {
					i++;
				}
			}
		}
		if(j==pattern.size()){
			cout<<i-j<<" is the start matching index"<<endl;
			return true;
		}
		return false;
	}
	
private:
	vector<int> prefixFunction(string pattern){
		
		vector<int> prefix(pattern.size());
		
		int j = 0;
		for(int i=1;i<pattern.size();i++){
			if(pattern[i]==pattern[j]){
				prefix[i] = j + 1;
				j++;
				i++;
			}
			else {
				if(j!=0){
					j = prefix[j-1];
				}
				else {
					prefix[i] = 0;
					i++;
				}
			}
		}
		return prefix;
	}
};


int main(){
	
	string str = "abcbcglx";
	string pattern = "bcgl";
	
	SubstringSearch ss;
	
	bool res = ss.KMP(str, pattern);
	if(res) cout<<pattern<<" is a substring of "<<str<<endl;
	else cout<<"No, it is not a substring"<<endl;
	
	
	return 0;
}
