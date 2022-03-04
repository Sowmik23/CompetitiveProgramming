#include <bits/stdc++.h>
using namespace std;


///Longest Substring with At Most K Distinct Characters


int lengthofLongestSubstringKDistinct(string s, int k){
	
	if(s=="" or s.empty()) return 0;
	int maxLen = 0, left = 0, right = 0, cnt = 0;
	
	map<char, int> mp;
	
	while(right<s.size()){
		char c1 = s[right];
		mp[c1]++;
		
		if(mp.size()>k) cnt++;
		right++;
		
		while(cnt>0){
			char c2 = s[left];
			mp[left]--;
			if(mp[c2]==0){
				mp.erase(c2);
				cnt--;
			}
			left++;
		}
		maxLen = max(maxLen, right-left);
	}
	
	return maxLen;
}


int main(){
	
	string str = "abcdefadaaaddfdf";
	int k = 5;
	
	cout<<lengthofLongestSubstringKDistinct(str, k)<<endl;
	
	
	
	return 0;
}
