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

int n, ans[mx],c[mx];
bool visited[mx];

int f(int w)
{
	if(w==0) return true;
	if(w<0) return false;
	
	if(visited[w]) return ans[w];
	
	for(int i=n-1;i>=0;i--)
	{
		bool x = f(w-c[i]);
		ans[w] = ans[w] or x;
	}
	visited[w]=true;
	
	return ans[w];
}

int main()
{
	int w;
	scanf("%d%d",&w,&n); 
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&c[i]) ;
	}
	
	if(f(w)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	return 0;
}
