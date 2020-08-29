#include <bits/stdc++.h>
using namespace std;

class Solution {
	stack<char> s;
	queue<char> q;
		
	public:
		void pushCharacter(char ch){
			s.push(ch);
		}
		void enqueueCharacter(char ch){
			q.push(ch);
		}
		char popCharacter(){
			char k = s.top();
			s.pop();
			return k;
		}
		char dequeueCharacter(){
			char k = q.front();
			q.pop();
			return k;
		}
};


int main(){
	string str;
	getline(cin, str);
	
	int len = str.length();
	Solution obj;
	for(int i=0;i<len;i++){
		obj.pushCharacter(str[i]);
		obj.enqueueCharacter(str[i]);
	}
	
	bool isPalindrome = true;
	for(int i=0;i<len/2;i++){
		if(obj.popCharacter() != obj.dequeueCharacter()){
			isPalindrome = false;
			break;
		}
	}
	
	if(isPalindrome) cout<<"The word, "<<str<<", is a palindrome."<<endl;
	else cout<<"The word, "<<str<<", is not a palindrome."<<endl;
	
	
	return 0;
}
