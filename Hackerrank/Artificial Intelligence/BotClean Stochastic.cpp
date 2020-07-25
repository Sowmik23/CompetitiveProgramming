#include <bits/stdc++.h>
using namespace std;

vector <string> str;

void nextMove(int x, int y, vector<string> str){
	int xx=-1, yy=-1;
	
	if(str[x][y]=='d') cout<<"CLEAN";
	else {
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(str[i][j]=='d'){
					xx = i;
					yy = j;
					break;
				}
			}
			if(xx!=-1) break;
		}
		int diffx = x - xx;
		int diffy = y - yy;
		
		if(diffx>0) cout<<"UP";
		else if(diffx<0) cout<<"DOWN";
		else if(diffy>0) cout<<"LEFT";
		else if(diffy<0) cout<<"RIGHT";
	}
}


int main(){
	
	int x, y;
	cin>>x>>y;
	string s;
	
	for(int i=0;i<5;i++) {
		cin>>s;
		str.push_back(s);
	}
	
	nextMove(x, y, str);
	
	return 0;
}
