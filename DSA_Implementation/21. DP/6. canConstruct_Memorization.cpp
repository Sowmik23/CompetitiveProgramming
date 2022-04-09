#include <bits/stdc++.h>
using namespace std;

///Write a function 'canConstruct(target, string)' that accepts a target
///string and an array of strings

///The function should return a boolean indicating whether or not the target 
///can be constructed by concatenating elements of the string array.



//recursion
//Time: O(n^m *m) , m = target length/height of the tree, n = str.size()
//Space: O(m)
bool canConstruct(vector<string> &str, string target){
	if(target=="") return true;
	
	
	for(int i = 0;i<str.size();i++){
		if(target.compare(0, str[i].size(), str[i])==0){ //compare prefix
			string suffix = target.substr(str[i].size(), target.size());
			//cout<<target<<" "<<str[i]<<" "<<suffix<<endl;
			if(canConstruct(str, suffix)==true){
				return true;
			}
		}
	}
	
	return false;
}

//recursion with memorization	
//Time: O(n*m^2)
//Space: O(m^2)
bool canConstructWithMemorization(vector<string> &str, string target, map<string, bool> &memo){
	if(target=="") return true;
	if(memo[target]) return memo[target];
	
	for(int i = 0;i<str.size();i++){
		if(target.compare(0, str[i].size(), str[i])==0){ //compare prefix
			string suffix = target.substr(str[i].size(), target.size());
		//	cout<<target<<" "<<str[i]<<" "<<suffix<<endl;
			if(canConstructWithMemorization(str, suffix, memo)==true){
				memo[target] = true;
				return true;
			}
		}
	}
	
	memo[target] = false;
	return false;
}


//tabulation method: iterative
//Time: O(m^2*n) ==>m = targetSum, n = nums.size() 
//Space: O(m)
bool canConstructWithTabulation(vector<string> &str, string target){
	
	vector<bool> dp(target.size()+1, false);
	dp[0] = true;

	for(int i = 0;i<=target.size();i++){
		if(dp[i]==true){
			for(int j=0;j<str.size();j++){				
				if(target.substr(i, i+str[j].size())==str[j]){ //compare prefix
					dp[i+str[j].size()] = true;
				}
			}
		}
	}
	
	return dp[target.size()];
}




int main(){
	
	vector<string> str;
	string target;
	
	str = {"ab", "abc", "cd", "def", "abcd"};
	target = "abcdef";
	cout<<canConstruct(str, target)<<endl; //true
	cout<<canConstructWithTabulation(str, target)<<endl;

	str = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	target = "skateboard";
	cout<<canConstruct(str, target)<<endl; //false


	str = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	target = "skateboard";
	//vector<bool> memo(target.size(), false);
	map<string, bool> memo;
	cout<<canConstructWithMemorization(str, target, memo)<<endl; //false
	cout<<canConstructWithTabulation(str, target)<<endl;
	
	str = {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
	target = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
	///here, we need to use map to initialize target
	//map<string, bool> memo;
	
	//memo = vector<string> (target.size(), false);
	//cout<<canConstructWithMemorization(str, target, memo)<<endl; //true

	cout<<canConstructWithTabulation(str, target)<<endl;
	
		
	str = {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
	target = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
	cout<<canConstructWithTabulation(str, target)<<endl;
		
	
	return 0;
}
