#include <bits/stdc++.h>
using namespace std;


//initial value of alpha and beta
const int MAX = +1000; //+inf
const int MIN = -1000;  //-inf

int minimax(int depth, int nodeIndex, bool maximizingPlayer, int values[], int alpha, int beta, int h){
	
	//terminating condition
	if(depth==h) return values[nodeIndex];

	if(maximizingPlayer){
		int best = MIN;
		
		for(int i=0;i<2;i++){
			int val = minimax(depth+1, nodeIndex*2 + i, false, values, alpha, beta, h);
			
			best = max(best, val);
			alpha = max(alpha, best);
			
			//alpha beta pruning
			if(alpha>=beta) break;
		}
		return best;
	} 
	else {
		int best = MAX;
		
		for(int i=0;i<2;i++){
			int val = minimax(depth + 1, nodeIndex*2 + i, true, values, alpha, beta, h);
			
			best = min(best, val);
			beta = min(beta, best);
			
			//alpha beta pruning
			if(alpha>=beta) break;
		}
		return best;
	}
}

//determine the tree depth
int log2(int n){
	if(n==1) return 0;
	return 1+log2(n/2);
}

int main(){
	
	int values[] = { 3, 4, 5, 6, 7, 9, 1, 2, 8 };
	
	int n = sizeof(values)/sizeof(values[0]);
	int h = log2(n);
	
	int ans = minimax(0, 0, true, values, MIN, MAX, h); 
	
	cout<<"Optimal value is: "<<ans<<endl;
	
	return 0;
}
