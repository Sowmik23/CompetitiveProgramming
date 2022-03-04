#include <bits/stdc++.h>
using namespace std;

//finding lenth of longest sub-string without repeating characters: 
///Time Complexity: O(n)

int lengthOfLongestSubstring(string s){
	
	int left =0, right=0;
	unordered_map<char, int> window;
	int res = 0; 
	
	while(right<s.size()){
		char c1 = s[right];
		window[c1]++;
		right++;
		
		///if a duplicate character appears in the window
		///move the left pointer
		while(window[c1]>1){
			char c2 = s[left];
			window[c2]--;
			left++;
		}
		res = max(res, right-left);  ///update maximum length
	}
	
	return res;
}


/*
 * Note:
 * when asked to find maximum substring, we should update maximum 
 * after the inner while loop to guarantee that the substring is 
 * valid. On the other hand, when asked to find minimum substring, 
 * we should update minimum inside the inner while loop.
*/



int main(){
	
	string str = "pwwkew";
	
	cout<<lengthOfLongestSubstring(str)<<endl;
	
	
	return 0;
}
