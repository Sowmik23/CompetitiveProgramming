#include <bits/stdc++.h>
using namespace std;

/// can find minimum element in O(1)

int main(){
	
	stack<pair<int, int>> stk;
	
	int n, x = 5;
	while(x--){
		scanf("%d", &n);
		
		
		int new_min = stk.empty() ? n : min(n, stk.top().second);
		
		stk.push({n, new_min}); 
	}
	
	/// print stack
	while(!stk.empty()){
		int k = stk.top().first;
		int min = stk.top().second;
		cout<<k<<" "<<min<<endl;
		stk.pop();
	}
	
	
	
	return 0;
}
