#include <bits/stdc++.h>
using namespace std;

void nextMove(int player, vector<string> board) {
	
	bool flag = false;
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(player==1) {
				if(board[i+1][j] == board[i][j+1] and board[i][j+1] == '1') {
					board[i+1][j] = 0;
					board[i][j+1] = 0;
					cout<<i<<" "<<j<<endl;
					flag = true;
					break;
				}
			}
			else if(player==2) {
				if(board[i+1][j] == board[i][j+1] and board[i][j+1] == '0') {
					board[i+1][j] = 1;
					board[i][j+1] = 1;
					cout<<i<<" "<<j<<endl;
					flag = true;
					break;
				}
			}
		}
		if(flag) break;
	}
}


int main(){
	
	int player;
	cin>>player;
	
	vector<string > board;
	
	for(int i=0;i<8;i++){
		string str;
		cin>>str;
		board.push_back(str);
	}
	
	nextMove(player, board);
	
	return 0;
}
