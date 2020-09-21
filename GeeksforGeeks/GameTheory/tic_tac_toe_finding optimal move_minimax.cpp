#include <bits/stdc++.h>
using namespace std;

//finding next optimal move in tac tac toe


struct Move {
	int row, col;
};

char player = 'x', opponnent = 'o';

//if there are moves reaminging on the board returns true else false
bool isMovesLeft(char board[3][3]) {
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[i][j]=='_') return true;
		}
	}
	return false;
}


//Evaluation function
int evaluate(char b[3][3]){
	//checking rows for 'x' or 'o' victory
	for(int row=0;row<3;row++){
		if(b[row][0]==b[row][1] and b[row][1]==b[row][2]) {
			if(b[row][0]==player) return +10;
			else if(b[row][0]==opponnent) return -10;
		}
	}
	
	//checking columns for 'x' or 'o' victory
	for(int col=0;col<3;col++){
		 if(b[0][col]==b[1][col] and b[1][col]==b[2][col]) {
			if(b[0][col]==player) return +10;
			else if(b[0][col]==opponnent) return -10;
		}
	}
	
	//checking diagonals for 'x' or 'o' victory
	if(b[0][0]==b[1][1] and b[1][1]==b[2][2]){
		if(b[0][0]==player) return +10;
		else if(b[0][0]==opponnent) return -10;
	}

	if(b[2][0]==b[1][1] and b[1][1]==b[0][2]){
		if(b[0][2]==player) return +10;
		else if(b[0][2]==opponnent) return -10;
	}

	//if match draw(non of them have won
	return 0;
}


//minimax function
//considers all the possible ways the game can go and 
//returns the value of the board
int minimax(char board[3][3], int depth, bool isMax){
	int score = evaluate(board);
	
	if(score==10) return score; //if maximizer won
	if(score==-10) return score; //if minimizer won
	if(isMovesLeft(board)==false) return 0; //if now winner/tie

	//maximizer's move
	if(isMax) {
		int best = -1000;
		
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(board[i][j]=='_'){
					board[i][j] = player; //make the player's move
				
					//call minimax recursively and choose the max value
					best = max(best, minimax(board, depth+1, !isMax));
					
					//undo the move
					board[i][j] = '_';
				}
			}
		}
		return best;
	}
	
	//if minimizer's move
	else {
		int best = -1000;
		
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(board[i][j]=='_'){
					board[i][j] = opponnent; //make the player's move
				
					//call minimax recursively and choose the min value
					best = min(best, minimax(board, depth+1, !isMax));
					
					//undo the move
					board[i][j] = '_';
				}
			}
		}
		return best;
	}
}


//this will return the best possible move for the player
Move findBestMove(char board[3][3]) {
	int bestVal = -10000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;
	
	//traverse all empty cell's and  return optimal value
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[i][j]=='_'){
				board[i][j] = player;
				
				int moveVal = minimax(board, 0, false);
				
				//undo move
				board[i][j] = '_';
				
				if(moveVal > bestVal){
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}
	
	cout<<"The value of the best move is: "<<bestVal<<endl;
				
	return bestMove;
}


int main(){
	
	char board[3][3] = {
		{'x', 'o', 'x' },
		{'o', 'o', 'x' },
		{ '_', '_', '_' }
	};
	
	Move bestMove = findBestMove(board);
	
	cout<<"Optimal move is "<<endl;
	cout<<"Row : "<<bestMove.row<<endl;
	cout<<"Col : "<<bestMove.col<<endl;
	
	return 0;
}
