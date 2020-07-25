#include <bits/stdc++.h>
using namespace std;

vector <string> str;

void nextMove(int x, int y,int n, vector<string> str){
	int xx=-1, yy=-1;
	
	if(str[x][y]=='d') cout<<"CLEAN";
	else {
		for(int i=0;i<n;i++){
			int len = str[i].size();
			//cout<<len<<endl;
			
			for(int j=0;j<len;j++){
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
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++) {
		cin>>s;
		str.push_back(s);
	}
	
	nextMove(x, y, n, str);
	
	return 0;
}

