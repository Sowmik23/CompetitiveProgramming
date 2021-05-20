#include <bits/stdc++.h>
using namespace std;

///Time Complexity: O(n)
///Substring with Concatenation of All Words
/*
 * You are given a string s and an array of strings words
 * of the same length. Return all starting indices of substring(s) 
 * in s that is a concatenation of each word in words exactly once, 
 * in any order, and without any intervening characters.

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
*/


vector<int> findSubstring(string s, vector<string> words){
	
	vector<int> res;
	unordered_map<string, int> mp;
	int len = words.size();
	
	for(auto i: words){
		mp[i]++;
	}
	
	int wordLength = words[0].length();  //as words are in same length
	int window = wordLength*len;
	
	if(window > s.length()) return res;   ///size() and length() are same
	
	for(int i=0;i<s.length()-window;i++){
		string slice = s.substr(i, window);
		
		int index=0, j=0;
		unordered_map<string, int> t;
		while(index<len){   ///just checking slice if it contains words
			string tmp = slice.substr(j, wordLength);
			j+=wordLength;
			t[tmp]++;
			index++;
		}
		if(t==mp){ ///comparing two unordered_map
			res.push_back(i);
		}
	}
	
	return res;
}


int main(){
	
	string s = "barfoofoobarthefoobarman";
	vector<string> words = {"bar","foo","the"};
	
	vector<int> ans = findSubstring(s, words);
	
	for(auto i: ans) cout<<i<<" ";
	cout<<endl;
	
	return 0;
}
