#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long, long long>  vl;
#define ll long long
#define db double
#define pll pair<ll ,ll >
#define pii pair<int, int >
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define inf 1e9
#define eps 1e-9
#define mx 10005
#define pi 2*acos(0.0)
#define si(a) scanf("%d",&a) 
#define sd(a) scanf("%lf",&a)
#define sl(a) scanf("%lld", &a)
#define dbg(x) cout<< #x <<" = "<<x<< endl
#define SET(a)  memset((a), -1, sizeof(a))
#define CLR(a)  memset((a), 0, sizeof(a))
#define read freopen("in.txt", "r", stdin)
#define write freopen("out.txt", "w", stdout)

int n, ans[mx][mx],fq[mx],c[mx];
bool visited[mx][mx];

int f(int w, int i)
{
	//cout<<"-> "<<w<<endl;
	if(w==0) return 0;
	if(w<0) return inf; 
	if(i<0) return inf;
	
	if(visited[w][i]) return ans[w][i];
	
	for(int j=0;j<=fq[i];j++)
	{
		int x=f(w-j*c[i],i-1)+j;
		ans[w][i]=min(ans[w][i],x);
	}
	visited[w][i]=true;
	
	return ans[w][i];
}

int main()
{
	int w;
	scanf("%d%d",&w,&n); 
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&c[i],&fq[i]) ;
	}
	
	cout<<f(w,n-1)<<endl;
	
	return 0;
}

