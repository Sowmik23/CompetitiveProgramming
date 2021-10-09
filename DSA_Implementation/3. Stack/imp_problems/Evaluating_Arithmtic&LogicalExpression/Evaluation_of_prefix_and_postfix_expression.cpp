#include <bits/stdc++.h>
using namespace std;


/// Evaluation of----------->>>>
//  Infix: 2 + 1 * 3

/// 1. Postfix expression (Another name is Reverse Polish Expression):
//     2 1 + 3 *  it's result is = 9
 
/// 2. Prefix expression( Polish Notation):
//      * + 2 1 3


//Note: consider that provided postfix expression is always valid


bool isOperator(char ch){
	if(ch=='^' or ch=='*' or ch=='/' or ch=='+' or ch=='-') return true;
	return false;
}

int calculate(int a, int b, char ch){
	if(ch=='^') return a^b;
	else if(ch=='*') return a*b;
	else if(ch=='/') return a/b;
	else if(ch=='+') return a+b;
	else if(ch=='-') return a-b;
	return -1;
}


int postfixEvaluation(string str){
	
	stack<int> stk;
	
	for(int i=0;i<str.size();i++){
		if( (str[i]>='0' and str[i]<='9') ){
			stk.push(str[i]-'0');
		}
		else if(isOperator(str[i])){
			 int b = stk.top();
			 stk.pop();
			 int a = stk.top();
			 stk.pop();
			 
			 int res = calculate(a, b, str[i]);
			 
			 stk.push(res);
		 }
	 }
	 
	 return stk.top();
 }



// Evaluation of prefix expression
int prefixEvaluation(string str){
	
	stack<int> stk;
	
	//here we need to traverse from right to left of the prefix expression
	for(int i=str.size()-1;i>=0;i--){
		if(str[i]>='0' and str[i]<='9'){
			stk.push(str[i]-'0');
		}
		else if(isOperator(str[i])){
			int b = stk.top();
			stk.pop();
			int a = stk.top();
			stk.pop();
			
			int res = calculate(a, b, str[i]);
			stk.push(res);
		}
	}
	return stk.top();
}



int main(){
	
	string postfix = "21+3*";
	
	int res = postfixEvaluation(postfix);
	cout<<res<<endl;
	
	string prefix = "*+213";
	res = prefixEvaluation(prefix);
	cout<<res<<endl;
	
	return 0;
}
