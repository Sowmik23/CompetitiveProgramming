#include <bits/stdc++.h>

using namespace std;

bool comp(char a, char b)
{
	if(tolower(a)==tolower(b)) return a<b;
	return tolower(a)<tolower(b);
}

int main(){
	
	int t, n, m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		/*char str[n+m];
		for(int i=0;i<n;i++) str[i] = '0';
		for(int i=n;i<n+m;i++) str[i] = '1';
		
		//cout<<str<<endl;
		int cnt=0;
		while(next_permutation(str,str+m+n,comp))
		{
			//cnt++;
			
			if(str[0]=='1') cnt++;
			//cout<<str[0]<<endl;
			//cout<<str<<endl;
		}
		cout<<cnt<<endl;*/
		
		cout<<m*n<<endl;
	}
	
	
	return 0;
}
