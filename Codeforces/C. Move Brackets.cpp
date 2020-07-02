#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main(){
	
	int t, l;
	cin>>t;
	while(t--)
	{
		cin>>l;
		char ch;
		
		int cnt=0, mn=100;
		
		for(int i=0;i<l;i++){
			cin>>ch;
			//cout<<ch<<endl;
			char x = '(';
			if(ch==x) cnt++;
			else cnt--;
			mn = min(mn, cnt);
			//cout<<cnt<<" at step 0"<<endl;
		}
		//cout<<"Take len"<<endl;

		cout<<mn*-1<<endl;

	}
	
	return 0;
}
