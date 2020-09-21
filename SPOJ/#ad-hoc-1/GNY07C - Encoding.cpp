#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int t;
	string str;
	cin>>t;
	int r, c;
	string res;
	for(int cse=1;cse<=t;cse++){
		res = "";
		cin>>r>>c;
		cin.ignore();
		getline(cin, str);
		
		for(int i=0;i<str.size();i++){
			int x;
			if(str[i] ==' ') x = 0;
			else x = str[i]-'A' + 1;
			//cout<<x<<endl;
			
			std::string binary = std::bitset<5>(x).to_string(); 
			//cout<<binary<<endl;
			res+=binary;
		}
		//cout<<res<<" main res"<<endl;
		
			int arr[r][c];
			memset(arr, 0, sizeof(arr));
			int idx = r*c - res.size();
			//cout<<idx<<" extra idx needed"<<endl;
			
			if(idx>0){
				for(int i=0;i<idx;i++){
					res= res+"0";
				}
				//cout<<res<<" after adding idx"<<endl;
			}
			
			int k=0, l=0, m=r, n=c;
			int j=0;
			
			//padding
			while(k<m and l<n){
				for(int i=l;i<n;i++){
					arr[k][i] = res[j++]-'0';
				}
				k++;
				for(int i=k;i<m;i++){
					arr[i][n-1] = res[j++]-'0';
				}
				n--;
				if(k<m){
					for(int i=n-1;i>=l;i--){
						arr[m-1][i] = res[j++]-'0';
					}
					m--;
				}
				if(l<n){
					for(int i=m-1;i>=k;i--){
						arr[i][l] = res[j++]-'0';
					}
					l++;
				}
			}
			
			//print res
			cout<<cse<<" ";
			for(int i=0;i<r;i++){
				for(int ii=0;ii<c;ii++){
					cout<<arr[i][ii];
				}
			}
			cout<<endl;
		}
		
	
	return 0;
}
