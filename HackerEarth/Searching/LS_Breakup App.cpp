#include <bits/stdc++.h>
using namespace std;


int ans[32];

void getDate(string str){
	stringstream ss;
	ss << str;
	
	string tmp;
	int found;
	while(!ss.eof()){
		ss>>tmp;
		if(stringstream(tmp)>>found){
			//cout<<found<<endl;
			if(str[0]=='G') ans[found]+=2;
			else ans[found]+=1;
		}
		
		tmp="";
	}
}


int main(){
	
	string str, tmp;
	
	int t;
	cin>>t;
	cin.ignore();
	
	
	
	while(t--){
		getline(cin, str);
		
		
		/// Processing the line and search any date
		getDate(str);
		//cout<<k<<endl;
	}
	
	int mx = 0, day;
	for(int i=1;i<=30;i++){
		//cout<<i<<" "<<ans[i]<<endl;
		if(ans[i]>mx){
			mx = ans[i];
			day = i;
		}
	}
	//cout<<endl;
	
	//cout<<mx<<" "<<day<<endl;
	
	if(day==19 or day==20) cout<<"Date"<<endl;
	else cout<<"No Date"<<endl;
	
	
	return 0;
}
