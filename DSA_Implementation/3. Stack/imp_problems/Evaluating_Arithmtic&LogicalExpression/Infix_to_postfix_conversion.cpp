#include <bits/stdc++.h>
using namespace std;


// <-**************** infix to postfix conversion***********->
/// Infix expression(input):    (a+b)*c-d+a (operand1 operator operand2)
/// Postfix expression(output):  ab+c*d-a+  (operand1 operand2 operator)

/// a+b ----> ab+

/// infix---->postfix


bool isOperator(char ch){
	if(ch=='^' or ch=='/' or ch=='*' or ch=='+' or ch=='-') return true;
	return false;
}

int Precedence(char ch){
	if(ch=='^') return 3;
	else if(ch=='*' or ch=='/') return 2;
	else if(ch=='+' or ch=='-') return 1;
	else return -1;
}


string InfixToPostfix(string str){
	
	stack<char> stk;
	string res = "";
	
	for(int i=0;i<str.size();i++){
		
		//if str[i] is operand, add it to output 
		if( (str[i]>='0' and str[i]<='9') or (str[i]>='a' and str[i]<='z') or (str[i]>='A' and str[i]<='Z')){
			res+=str[i];
		}
		//if str[i] is '(' opening bracket then push it to the stack
		else if(str[i]=='('){
			stk.push('(');
		}
		//if closing bracket ')' then scan stack until  opening bracket ')' 
		else if(str[i]==')'){
			while(stk.top()!='('){
				res+=stk.top();
				stk.pop();
			}
			stk.pop();
		}
		//if str[i] is an operator
		else if(isOperator(str[i])){
			while(!stk.empty() and Precedence(str[i]) <= Precedence(stk.top())){
				res+=stk.top();
				stk.pop();
			}
			stk.push(str[i]);
		}
	}
	
	//pop all the remaining element from the stack and add to the res string
	while(!stk.empty()){
		res+=stk.top();
		stk.pop();
	}
	
	return res;
}


int main(){
	
	string infix = "2+3*(5^4-9)^(2+7*8)-6";
	//string infix = "a=b*(c^d-e)^(f+g*h)-i";
	
	string res = InfixToPostfix(infix);
	cout<<res<<endl;
	
	return 0;
}
