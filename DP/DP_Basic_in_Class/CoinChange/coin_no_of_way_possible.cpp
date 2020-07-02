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


int n, ans[mx][mx],c[mx];
bool visited[mx][mx];

int f(int w, int i){
	if(w==0) return 1;
	if(w<0 or i<0) return 0;
	
	if(visited[w][i]) return ans[w][i];
	
	visited[w][i]=true;
	
	int a=f(w,i-1);
	int b=f(w-c[i],i-1);
	
	return ans[w][i]=a+b;
}

int main()
{
	int w;
	scanf("%d%d",&w,&n); 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&c[i]) ;
	}
	
	cout<<f(w,n-1)<<endl;
	return 0;
}
