#include <bits/stdc++.h>
using namespace std;


///Longest Repeating Character Replacement


int getMax(map<char, int> mp){
	int mx = 0;
	for(auto i: mp){
		mx = max(mx, i.second);
	}
	return mx;
}



int characterReplacement(string s, int k){
	
	if(s=="" or s.empty()) return 0;
	
	int res = 0, left = 0, right = 0, cnt = 0;
	
	map<char, int> mp;
	while(right<s.size()){
		char c1 = s[right];
		mp[c1]++;
		
		if(cnt<mp[c1]) cnt = mp[c1];
		right++;
		
		while(!(right-left-cnt <=k)){
			char c2 = s[left];
			mp[c2]--;
			cnt = getMax(mp);
			left++;
		}
		res = max(res, right-left);
	}
	
	return res;
}


int main(){
	
	string str = "abdfdfaaaa";
	int k = 3;
	
	
	cout<<characterReplacement(str, k)<<endl;
	
	
	return 0;
}
