#include <bits/stdc++.h>
using namespace std;

///Time Complexity: O(n)

/*
Given a string S and a string T. Find the minimum window in S which
will contain all the characters of T in complexity O(n).
*/


string minWindowSubstring(string s, string t){
	//initialize the starting position and length of the sortest
	//substring
	int start = 0, minLen = INT_MAX;
	int left =0, right = 0;
	
	unordered_map<char, int> window; //counts the substrings char
	unordered_map<char, int> needs;  //keeps count of T strings chars
	
	for(char c: t){
		needs[c]++;
	}
	
	int match = 0;
	
	while(right < s.size()){
		char c1 = s[right];
		if(needs.count(c1)) {  //if c1 exists in needs
			window[c1]++;
			if(window[c1]==needs[c1]){
				match++;
			}
		}
		right++;
		
		while(match==needs.size()){ 
			//update result here if finding minimum
			if(right-left < minLen){
				//update the position and length of the smallest string
				start = left;
				minLen = right-left;
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
	
	//return null or the existing sub-string
	return minLen == INT_MAX ? "": s.substr(start, minLen);
}



int main(){
	
	string s, t;
	
	s = "ADOBECODEBANC";
	t = "ABC";
	
	cout<<minWindowSubstring(s, t)<<endl;
	
	return 0;
}
