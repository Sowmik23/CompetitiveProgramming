#include <bits/stdc++.h>
using namespace std;

string str[6];


int update_position(int x, int y, vector<pair<int,int>>dirties){
	vector<double> nearest_dirt;
	
	for(int i =0;i<dirties.size();i++){
		//find Euclidean distance
		double res = sqrt((pow(dirties[i][0] - x), 2) + (pow(dirties[i][1] - y), 2))
		nearest_dirt.push_back(res);
	}
	sort(nearest_dirt.begin(), nearest_dirt.end());
	
	return nearest_dirt[0];
}

int next_move(int x, int y){
	
	vector<pair<int, int> > dirties, next_dirt;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(str[i][j]=='d'){
				dirties.push_back(make_pair(i,j));
			}
		}
	}
	
	next_dirt = update_position(x, y, dirties);
	

	return 0;
}

int main(){
	
	int x, y;
	cin>>x>>y;
	
	for(int i=0;i<5;i++) cin>>str[i];
	
	string move;
	int i=x, j=y;
	//for(int i=x;i<5;i++){
		//for(int j=y;j<5;j++){
			if(str[i][j]=='d'){
				str[i][j] = 'd';
				move = "CLEAN";
			}
			else if(str[i][j+1]=='d'){
				if(str[i][j]!='d') str[i][j] = '-';
				else str[i][j] = 'd';
				move = "RIGHT";
			}
			else if(str[i][j-1]=='d'){
				if(str[i][j]!='d') str[i][j] = '-';
				else str[i][j] = 'd';
				move = "LEFT";
			}
			else if(str[i+1][j]=='d'){
				if(str[i][j]!='d') str[i][j] = '-';
				else str[i][j] = 'd';
				move = "DOWN";
			}
			else if(str[i-1][j]=='d'){
				if(str[i][j]!='d') str[i][j] = '-';
				else str[i][j] = 'd';
				move = "UP";
			}
			else if(str[i][j+1]=='-'){
				if(str[i][j]!='d') str[i][j] = '-';
				else str[i][j] = 'd';
				str[i][j+1] = 'b';
				move = "RIGHT";
			}
			else if(str[i][j-1]=='-'){
				if(str[i][j]!='d') str[i][j] = '-';
				else str[i][j] = 'd';
				str[i][j-1] = 'b';
				move = "LEFT";
			}
			else if(str[i+1][j]=='-'){
				if(str[i][j]!='d') str[i][j] = '-';
				else str[i][j] = 'd';
				str[i+1][j] = 'b';
				move = "DOWN";
			}
			else if(str[i-1][j]=='-'){
				if(str[i][j]!='d') str[i][j] = '-';
				else str[i][j] = 'd';
				str[i-1][j] = 'b';
				move = "UP";
			}
		//}
	//}
	cout<<move<<endl;
	/*for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<str[i][j];
		}
		cout<<endl;
	}*/
	
	
	return 0;
}
