#include <bits/stdc++.h>
using namespace std;


///Time Complexity: O(n)


vector<int> findAnagrams(string s, string p){
	
	vector<int> res;
	//int start = 0, minLen = INT_MAX;
	int left = 0, right = 0;
	
	map<char, int> window;
	map<char, int> needs;
	
	for(char i: p){
		needs[i]++;
	}
	
	int match = 0;
	
	while(right<s.size()){
		char c1 = s[right];
		if(needs.count(c1)){
			window[c1]++;
			if(window[c1]==needs[c1]){
				match++;
			}
		}
		right++;
		
		while(match==needs.size()){
			if(right-left == p.size()){
				//minLen = right-left;
				//start = left;
				res.push_back(left);
			}
			
			char c2 = s[left];
			if(needs.count(c2)){
				window[c2]--;
				if(window[c2]<needs[c2]){
					match--;
				}
			}
			left++;
		}
	}
	
	return res;
}



int main(){
	
	string s, p;
	
	s = "cbaebabacd";
	p = "abc";
	
	
	vector<int> res = findAnagrams(s, p);
	
	cout<<"Start index of the anagrams are: ";
	for(auto i: res){
		cout<<i<<" ";
	}
	cout<<endl;
	
	
	return 0;
}

