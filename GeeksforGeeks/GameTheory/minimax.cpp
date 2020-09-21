#include <bits/stdc++.h>
using namespace std;

/*finding maximum score that 
 * 
 * maximizing player can get
 * 
*/

int minimax(int depth, int nodeIndex, bool isMax, int scores[], int h){
	//depth 	-> current depth in game tree
	//nodeIndex -> index of current node in scores[]
	//isMax 	-> is true if current move is of maximizer, else false
	//scores[] 	-> stores leaves of game tree
	//h 		-> is maximum height of game tree
	
	//if leaf node is reached(terminating condition)
	if(depth == h) return scores[nodeIndex];
	
	if(isMax) {
		return max(minimax(depth+1, nodeIndex*2, false, scores, h), minimax(depth+1, nodeIndex*2 + 1, false, scores, h));
	}
	else {
		return min(minimax(depth+1, nodeIndex*2, true, scores, h), minimax(depth+1, nodeIndex*2 + 1, true, scores, h));
	}
}


int log2(int n){
	
	if(n==1) return 0;
	return 1+log2(n/2);
}


int main(){
	
	int scores[] = {3, 5, 2, 9};	//scores[] 	-> stores leaves of game tree
	
	int n = sizeof(scores)/sizeof(scores[0]);
	int hight  = log2(n);
	
	int res = minimax(0, 0, true, scores, hight);
	
	cout<<"The optimal value is : "<<res<<endl;
	
	return 0;
}
