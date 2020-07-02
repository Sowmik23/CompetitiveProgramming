#include <bits/stdc++.h>
using namespace std;

int main()				/*Nice typer Problem You can Learn a lot from it about String */
{
	int t;
	
	scanf("%d",&t);
	while(t--)
	{
		string str;
		cin>>str;
		int len = str.size();
		int l = len;
		
		int m = ceil(sqrt(len)); 
		len = l+m;
		
		
		string temp(m*m-l,'*');
		str.append(temp);
		//cout<<str<<endl;
		
		
		/* Same kaj kore ei jaygata.........
		 for(int i=l;i<(l+m);i++)
		{
			str[i] = '*';
		}
		for(int i=0;i<len;i++) cout<<str[i]; */
		
		
		string res;
		for(int i=0;i<m;i++)
		{
			for(int j=m-1;j>=0;j--)
			{
				res.push_back(str.at(m*j+i));
			}
		}
		//cout<<res<<endl;
		
		/*Same kaj korechilam eivabe.....
		int d=1;
		int b[10000];
		for(int i=0;;i++)
		{
			b[i] = len-m*d;
			d++;
			if(b[i]==0) break;
		}
		//for(int i=0;i<d-1;i++) cout<<b[i]<<endl;
		int k=0;
		string ans,res;
		
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<m;j++)
			{
				int dd = b[j]+i;
				//cout<<str[dd]<<endl;
				ans[k] = str[dd];
				k++;
			}
		}
		ans[k]='\0';
		cout<<ans<<endl;  */
		
		
		for(int i=0;i<res.size();i++)
		{
			if(res.at(i)=='*')
			{
				res.erase(res.begin()+i);
				i--;
			}
		}
		
		/*Same kaj evabeo kora jeto.....;)
		int j=0;
		for(int i=0;i<len;i++)
		{
			if(ans[i]!='*') 
			{
				res[j] = ans[i];
				j++;
			}
		}
		res[j] = '\0';*/
		
		cout<<res<<endl;
	}
	
	return 0;
}
