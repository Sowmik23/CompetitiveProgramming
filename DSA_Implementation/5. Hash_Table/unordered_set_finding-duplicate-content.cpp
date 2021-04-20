#include <bits/stdc++.h>
using namespace std;

//This is like <HashSet>

bool findDuplicate(vector<int> v){
	
	unordered_set<int> uset;
	unordered_set<int> duplicates;
	
	bool flag = false;
	for(int i=0;i<v.size();i++){
		if(uset.find(v[i]) == uset.end()){
			//that means v[i] is not found here
			uset.insert(v[i]);
		}
		else { //this is duplicate
			duplicates.insert(v[i]);
			flag = true;
		}
	}
	
	unordered_set<int> :: iterator it;
	for(it=duplicates.begin();it!=duplicates.end();it++){
		cout<<*it<<" ";
	}
	if(flag==true) return true;
	else return false;
}



int main(){
	
	vector<int> v;
	
	v = {3,4, 5, 6, 7, 2,3, 4, 3};
	
	bool f = findDuplicate(v);
	
	
	return 0;
}
