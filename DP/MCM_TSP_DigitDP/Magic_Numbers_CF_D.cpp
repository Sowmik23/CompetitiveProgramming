#include <bits/stdc++.h>
using namespace std;

const long long MOD=(1e9)+7;

int m,d,len;
string a,b,str;
long long visited[2005][2005][5];

//flag =1 if prefix<str

long long dp(int pos,int mod,int flag)
{
	if(pos==len) return (mod==0);
	
	if(visited[pos][mod][flag]!=-1) return visited[pos][mod][flag];
	
	long long ans = 0;
	if(flag)
	{
		if(pos%2==1)
		{
			ans+=dp(pos+1,(mod*10+d)%m,flag)%MOD;
		}
		else 
		{
			for(int i=0;i<=9;i++)
			{
				if(i==d) continue;
				ans+=dp(pos+1,(mod*10+i)%m,flag)%MOD;
			}
		}
	}
	else 
	{
		if(pos%2==1)
		{
			int k = str[pos]-'0';
			if(d==k) ans+=dp(pos+1,(mod*10+d)%m,0)%MOD;
			else if(d<k) ans+=dp(pos+1,(mod*10+d)%m,1)%MOD;
		}
		else 
		{
			int k = str[pos]-'0';
			for(int i=0;i<=k;i++)
			{
				if(i==d) continue;
				int next =0;
				if(i!=k) next =1;
				ans+=dp(pos+1,(mod*10+i)%m,next)%MOD;
			}
		}
	}
	return visited[pos][mod][flag]= ans;
}

int check(string a)
{
	int l = a.size();
	long long res = 0;
	for(int i=0;i<l;i++)
	{
		if(i%2==0 and a[i]-'0' ==d) return 0;
		else if(i%2==1 and a[i]-'0' !=d) return 0;
		res = res*10+(a[i]-'0');
		res%=m;
	}
	if(res) return 0;
	return 1;
}

int main()
{
	string a,b;
	scanf("%d%d",&m,&d);
	cin>>a>>b;

	str = a;
	len = str.size();
	memset(visited,-1,sizeof(visited));
	long long ans1 = dp(0,0,0);
	
	str = b;
	memset(visited,-1,sizeof(visited));
	long long ans2 = dp(0,0,0);
	
	ans2 = (ans2-ans1)%MOD;
	ans2+=check(a);
	ans2%=MOD;
	
	cout<<ans2<<endl;
	
	return 0;
}
