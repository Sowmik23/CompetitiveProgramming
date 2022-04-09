#include <bits/stdc++.h>
using namespace std;

///Write a function 'countConstruct(target, string)' that accepts a target
///string and an array of strings

///The function should return the number of ways that the target 
///can be constructed by concatenating elements of the string array.

///you may reuse elements of "string array' as many time as needed



//recursion
//Time: O(n^m *m) , m = target length/height of the tree, n = str.size()
//Space: O(m)
int countConstruct(vector<string> &str, string target){
	if(target=="") return 1;
	
	int totalCnt = 0;
	
	for(int i = 0;i<str.size();i++){
		if(target.compare(0, str[i].size(), str[i])==0){ //compare prefix
			string suffix = target.substr(str[i].size(), target.size());
			///cout<<target<<" "<<str[i]<<" "<<suffix<<endl;
			int numWaysForRest = countConstruct(str, suffix);
			totalCnt+=numWaysForRest;
		}
	}
	
	return totalCnt;
}

//recursion with memorization	
//Time: O(n*m^2)
//Space: O(m^2)
int countConstructWithMemorization(vector<string> &str, string target, vector<string> &memo){
	if(target=="") return 1;
	if(memo[target]) return memo[target];
	
	int totalCnt = 0;
	
	for(int i = 0;i<str.size();i++){
		if(target.compare(0, str[i].size(), str[i])==0){ //compare prefix
			string suffix = target.substr(str[i].size(), target.size());
			///cout<<target<<" "<<str[i]<<" "<<suffix<<endl;
			int numWaysForRest = countConstructWithMemorization(str, suffix, memo);
			totalCnt+=numWaysForRest;
		}
	}
	
	memo[target] = totalCnt;
	return totalCnt;
}


//tabulation method: iterative
//Time: O(m^2*n) ==>m = targetSum, n = nums.size() 
//Space: O(m)
int countConstructWithTabulation(vector<string> &str, string target){
	vector<int> dp(target.size()+1, 0);
	dp[0] = 1;

	for(int i = 0;i<=target.size();i++){
		for(int j=0;j<str.size();j++){				
			if(target.substr(i, i+str[j].size())==str[j]){ //compare prefix
				dp[i+str[j].size()] += dp[i];
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
	cout<<countConstruct(str, target)<<endl; //1


	str = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	target = "skateboard";
	cout<<countConstruct(str, target)<<endl; //0
	
	str = {"a", "p", "ent", "enter", "ot", "o", "t"};
	target = "enterapotentpot";
	cout<<countConstruct(str, target)<<endl; //4


	str = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	target = "skateboard";
	vector<string> memo;
	//map<string, bool> memo;
	cout<<countConstructWithMemorization(str, target, memo)<<endl; //false

	
	str = {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
	target = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
	///here, we need to use map to initialize target
	memo = vector<string> ();
	cout<<countConstructWithMemorization(str, target, memo)<<endl; //true
		
	return 0;
}

