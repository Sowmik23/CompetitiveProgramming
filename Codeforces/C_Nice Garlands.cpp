#include <bits/stdc++.h> 
using namespace std;

int main()
{
	int n,cnt=0;
	string str;
	scanf("%d",&n);
	cin>>str;
	
	int len = str.size();
	
	char c;
	char a = str[0];
	char b = str[1];
	
	string ans= "";
	ans+=a;
	ans+=b;
	
	if(len>2)
	{
		for(int i=2;i<len;i++)
		{
	
		c = str[i];
		
			if(c==a){
				if(a=='R' && b=='G'){
					c = 'B';
				}
				else if(a=='R' && b=='B'){
					c = 'G';
				}
				else if(a=='B' && b=='G'){
					c = 'R';
				}
				else if(b=='R' && a=='G'){
					c = 'B';
				}
				else if(b=='R' && a=='B'){
					c = 'G';
				}
				else if(b=='B' && a=='G'){
					c = 'R';
				}
				cnt++;
				ans+=c;
				a = b;
				b = c;
			}
			else if(c==b){
				if(a=='R' && b=='G'){
					c = 'B';
				}
				else if(a=='R' && b=='B'){
					c = 'G';
				}
				else if(a=='B' && b=='G'){
					c = 'R';
				}
				else if(b=='R' && a=='G'){
					c = 'B';
				}
				else if(b=='R' && a=='B'){
					c = 'G';
				}
				else if(b=='B' && a=='G'){
					c = 'R';
				}
				cnt++;
				ans+=c;
				a = b;
				b = c;
			}
			else {
				a = b;
				b = c;
				
				ans+=c;
			}
			
		}
			
	}
	
	printf("%d\n",cnt);
	cout<<ans<<endl;
	
	
	return 0;
}
