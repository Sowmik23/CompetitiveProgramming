/*
         Author: Ishmeet Dosanjh
         Date of Created: 1/12/1
         Version: 0.1 
         */
          
         //#pragma comment(linker, "/stack:20000000")
         //#pragma GCC optimize("Ofast")
         //#pragma GCC optimize("unroll-loops")
         //#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
          
         #define _CRT_SECURE_NO_WARNINGS
         # include <climits>
         # include <iostream>
         # include <cmath>
         # include <algorithm>
         # include <stdio.h>
         # include <cstdint>
         # include <cstring>
         # include <string>
         # include <cstdlib>
         # include <vector>
         # include <bitset>
         # include <map>
         # include <queue>
         # include <ctime>
         # include <stack>
         # include <set>
         # include <list>
         # include <random>
         # include <deque>
         # include <functional>
         # include <iomanip>
         # include <sstream>
         # include <fstream>
         # include <complex>
         # include <numeric>
         # include <immintrin.h>
         # include <cassert>
         # include <array>
         # include <tuple>
         # include <unordered_set> //i ngcc 6.6
         # include <ext/pb_ds/assoc_container.hpp>
         # include <ext/pb_ds/tree_policy.hpp>
         // #include "boost/algorithm/string.hpp"
         using namespace std;
          
         // Let's define unordered map
         # ifdef __GNUC__
         # if __cplusplus > 199711L
         # include <unordered_set>
         # include <unordered_map>
         # else
         # include <tr1/unordered_map>
         # include <tr1/unordered_set>
         using namespace tr1;
         # endif
         # else
         # include <unordered_map>
         # include <unordered_set>
         # endif
      
         //by zs coder magic 
         using namespace __gnu_pbds;
          
         #define fi first
         #define se second
         #define mp make_pair
         #define pb push_back
         #define fbo find_by_order
         #define ook order_of_key
         #define minus minu
         #define lgn 20
         #define INTMAX 200000000 
         #define si short int
         mt19937 gen(time(NULL));
         #define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
         // #define all(a) (a).begin(), (a).end()
         // #define endl '\n'
         // everything at the end but first uses trace
         
         // everything at the end but first uses trace
      
         #define TRACE
         #ifdef TRACE
         #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
             template <typename Arg1>
             void __f(const char* name, Arg1&& arg1){
                 cout << name << " : " << arg1 << std::endl;
                 //use cerr if u want to display at the bottom
             }
             template <typename Arg1, typename... Args>
             void __f(const char* names, Arg1&& arg1, Args&&... args){
                 const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
             }
         #else
         #define trace(...)
         #endif
      
      
      
         #define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 6,5,4,3,2,1))
         #define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
         #define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,_6,N,...) N
         #define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
         #define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
         #define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
         #define macro_dispatcher___(macro, nargs) macro ## nargs
         #define DBN1(a)           cerr<<#a<<"="<<(a)<<"\n"
         #define DBN2(a,b)         cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
         #define DBN3(a,b,c)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
         #define DBN4(a,b,c,d)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
         #define DBN5(a,b,c,d,e)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
         #define DBN6(a,b,c,d,e,f) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
         #define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
         #define DA(a,n) cerr<<#a<<"=["; printarray(a,n); cerr<<"]\n"
         #define DAR(a,n,s) cerr<<#a<<"["<<s<<"-"<<n-1<<"]=["; printarray(a,n,s); cerr<<"]\n"
          
         #ifdef _MSC_VER
         #define PREFETCH(ptr, rw, level) ((void)0)
         #else
         #define PREFETCH(ptr, rw, level) __builtin_prefetch(ptr, rw, level)
         #endif
          
         #ifdef LOCAL
         #define CURTIME() cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl
         #else
         #define CURTIME()
         #endif
         typedef long long ll;
         typedef unsigned int uint;
         typedef unsigned long long ull;
         typedef double d;
         typedef float f;
         // typedef long float lf; till now this thing included in an double data type but not in c sharp //
         typedef pair<int, int> pii;
         typedef pair<long long, long long> pll;
         typedef vector<int> vi;
         typedef vector<long long> vll;
         typedef int itn;
         typedef long l;
         typedef long double ld; 
      
      
         //~~~~~~~~~~~~~~~~ very very imp typedefs~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
         typedef priority_queue<ll, vector<ll> > max_pq;
         // typedef priority_queue<pii, vector<pii> , greater<pii >  > min_pq;
         ll toint(const string &s) {stringstream ss; ss << s; ll x; ss >> x; return x;}
         string tostring ( ll number ){stringstream ss; ss<< number; return ss.str();}
          
         typedef priority_queue<pair < ll , pair < pii , ll > >  , vector<pair < ll , pair < pii , ll > >  > ,greater<pair < ll , pair < pii , ll > >  > > min_pq;
      
         typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
         //2 tree here now
      
         typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > OST;
         // typedef priority_queue< pair < ll,pii >  , vector<pair <ll,pii>> > max_pq;
         // typedef priority_queue<pair <pii,pii>, vector<pair <pii,pii> > , greater <pair <pii,pii> >  > min_pq;
      
      
      
      
      
         typedef set<ll>::iterator sit;
         typedef map<ll,ll>::iterator mit;
         typedef list<ll>::iterator lit;
         
         /***************************************************************/
         // TEMPLATE DECLARATIONS 
         template<class T1, class T2, class T3>
         struct triple{ T1 a; T2 b; T3 c; triple() : a(T1()), b(T2()), c(T3()) {}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };
         template<class T1, class T2, class T3>
         bool operator<(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a<t2.a;else if(t1.b!=t2.b)return t1.b<t2.b;else return t1.c<t2.c;}
         template<class T1, class T2, class T3>
         bool operator>(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a>t2.a;else if(t1.b!=t2.b)return t1.b>t2.b;else return t1.c>t2.c;}
         #define tri triple<int,int,int>
         #define trll triple<ll,ll,ll>
          
             
         template<typename T = int>
         inline T read() {
             T val = 0, sign = 1; char ch;
             for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
                 if (ch == '-') sign = -1;
             for (; ch >= '0' && ch <= '9'; ch = getchar())
                 val = val * 10 + ch - '0';
             return sign * val;
         }
         //for 1 based arrays 
          
         #define FI2(n) for(int i=1;i<=(n);++i)
         #define FJ2(n) for(int j=1;j<=(n);++j)
         #define FK2(n) for(int k=1;k<=(n);++k)
         //for 0 based indexed arrays 
         #define FI(n) for(long i=0;i<(n);i++)
         #define FJ(n) for(long long j=0;j<(n);j++)
         #define FK(n) for(int k=0;k<(n);++k)
         #define FL(n) for(int l=0;l<(n);++l)
         #define FQ(n) for(int q=0;q<(n);++q)
         #define FOR(i,a,b) for(int i = (a), __e = (int) (b); i < __e; ++i)
         //special loops
         #define revp(i,n) for(i=(n-1);i>=0;i--)
         #define myrep1(i,a,b) for(i=a;i<=b;i++)
         #define myrep2(i,a,b) for(i=b;i>=a;i--)
      
         #define all(a) std::begin(a), std::end(a)
         #define reunique(v) v.resize(std::unique(v.begin(), v.end()) - v.begin())
          
         #define sqr(x) ((x) * (x))
         #define sqrt(x) sqrt(1.0 * (x))
         #define pow(x, n) pow(1.0 * (x), n)
          
         #define COMPARE(obj) [&](const std::decay_t<decltype(obj)>& a, const std::decay_t<decltype(obj)>& b)
         #define COMPARE_BY(obj, field) [&](const std::decay_t<decltype(obj)>& a, const std::decay_t<decltype(obj)>& b) { return a.field < b.field; }
          
         #define checkbit(n, b) (((n) >> (b)) & 1)
         #define setbit(n, b) ((n) | (static_cast<std::decay_t<decltype(n)>>(1) << (b)))
         #define removebit(n, b) ((n) & ~(static_cast<std::decay_t<decltype(n)>>(1) << (b)))
         #define flipbit(n, b) ((n) ^ (static_cast<std::decay_t<decltype(n)>>(1) << (b)))
       
          
          
         //some modulus and gcd type functions  
          
          
         const int mod = 1e9 + 7 ;
         const l maxn =200500;
         const ll inf=(2e9) + 2;// 2 foloowed by the 9 zeros and then adding two to it 
         
         ll powmod(ll a,ll b) {ll res=1;if(a>=mod)a%=mod;for(;b;b>>=1){if(b&1)res=res*a;if(res>=mod)res%=mod;a=a*a;if(a>=mod)a%=mod;}return res;}
         ll gcd(ll a , ll b){return a==0?b:gcd(b%a,a);}//recursive gcd algorithm EUCLIDEAN dreamplay 
         
         long mygcd(long a, long b)
 {
     if (a == 0)//more described euclidean algorithm 
         return b;
     else if (b == 0)
         return a;
  
     if (a < b)
         return gcd(a, b % a);
     else
         return gcd(b, a % b);
 }
         
         
         
         // Useful constants
         // C function for extended Euclidean Algorithm //advanced stuff 
         ll gcdExtended(ll a, ll b, ll *x, ll *y)//this is used for MMI when both a and m are coprime gcd(a,m)=1
         {
             // Base Case
             if (a == 0)
             {
                 *x = 0;
                 *y = 1;
                 return b;
             }
          
             ll x1, y1; // To store results of recursive call
             ll gcd = gcdExtended(b%a, a, &x1, &y1);
          
             // Update x and y using results of recursive
             // call it uses the property and i done it manually too
             *x = y1 - (b/a) * x1;
             *y = x1;
          
             return gcd;
         }
          
          int some_primes[7] = {24443, 100271, 1000003, 1000333, 5000321, 98765431, 1000000123};
          
         template<typename T>
         T getint() {
             T x=0,p=1;
             char ch;
             do{ch=getchar();}while(ch <= ' ');
             if(ch=='-')p=-1,ch=getchar();
             while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
             return x*p;
         }

         // mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

         template<typename T1,typename T2>bool umin(T1 &x,const T2&y){if(x>y)return x=y,true;return false;}
         template<typename T1,typename T2>bool umax(T1 &x,const T2&y){if(x<y)return x=y,true;return false;}

         
         const int maxq=(int)2e6+10;
         const ll llinf=(ll)1e18+5;
         const ld pi=acos(-1.0);
          
          
         #define T9          1000000000
         #define T18         1000000000000000000LL
         #define INF         1011111111
         #define LLINF       1000111000111000111LL
          
         #define EPS         (double)1e-10
         #define PI          3.14159265358979323846264
         #define link        asaxlajrewqwe
         #define rank        wahayawehasdakw
         // modulo
         #define modsign %
         #define NUM  1000000007
         #define NUM1 1000000009
         //scanf type macros 
         #define s(n) scanf("%d", &n)
         #define sl(n) scanf("%ld", &n)
         #define sl3(n1,n2,n3) scanf("%lld %lld %lld ", &n1, &n2, &n3)
         #define sl4(n1,n2,n3,n4) scanf("%ld %ld %ld %ld", &n1, &n2, &n3, &n4)
         #define sll(n) scanf("%I64ld", &n)
         #define sll2(n) scanf("%lld", &n)
         //printf type macros 
         #define p(n) printf("%d\n", n)
         #define pl(n) printf("%ld\n",n)
         #define pl3(n1,n2,n3) printf("%lld %lld %lld\n ", n1, n2, n3)
         #define pl4(n1,n2,n3,n4) printf("%ld %ld %ld %ld\n ", n1, n2, n3, n4)
         #define pll(n) printf("%I64d\n",n)
         #define pll2(n) printf("%lld\n",n)
         //cin cout type macros  
         #define ct1(n1) cout<<n1<<"\n"
         #define ct2(n1,n2) cout<<n1<<" "<<n2<<"\n"
         #define ct3(n1,n2,n3) cout<<n1<<"\n"<<n2<<"\n"<<n3<<"\n"
         #define ct4(n1,n2,n3,n4) cout<<n1<<"\n"<<n2<<"\n"<<n3<<"\n"<<n4<<"\n"
         #define ci1(n1) cin>>n1
         #define ci2(n1,n2) cin>>n1>>n2
         #define ci3(n1,n2,n3) cin>>n1>>n2>>n3
         #define ci4(n1,n2,n3,n4) cin>>n1>>n2>>n3>>n4
         
          
     //*************************************************************************************
         int32_t solve();   
         // A utility function to check whether n is power of 2 or not. See http://goo.gl/17Arj
         //global arraya outside the function always 
         // int dp[1004];
         // long long ncr[1004][1004]; // i uses this thing for the binomial coefficients 
      
         int isPowerOfTwo(unsigned n)
         {  return n && (! (n & (n-1)) ); }//very imp
         //geeks understanding and learning
         
         //*******************************
         // To compute x^y under modulo m in o(logy) recursive modualr exponentiation 
         
         //dishighlighted only for the   BROKEN CLOCK  CLOCKS_PER_SEC
         // ll expower(ll x, ll y, ll m)
         // {
         // if (y == 0)
         //     return 1;
         // ll p = expower(x, y/2, m) % m;
         // p = (p * p) % m;
      
         // return (y%2 == 0)? p : (x * p) % m;
         // }
         // *******************************
         
         ll mypower(ll x,ll y)
         {
             ll res = 1;      // Initialize result
          
             // x = x % p;  // Update x if it is more than or 
                         // equal to p
         
             while (y > 0)
             {
                 // If y is odd, multiply x with result
                 if (y & 1)
                     // res = (res*x) % p;
          res=res*x;
                 // y must be even now
                 y = y>>1; // y = y/2
                 // x = (x*x) % p; 
                 x*=x;
             }
             return res;
             }
             /* Iterative Function to calculate (x^y)%p in O(log y) */
         ll mypower2(ll x,ll y, ll p)
         {
             ll res = 1;      // Initialize result
          
             x = x % p;  // Update x if it is more than or 
                         // equal to p
         
             while (y > 0)
             {
                 // If y is odd, multiply x with result
                 if (y & 1)
                     res = (res*x) % p;
                 // y must be even now
                 y = y>>1; // y = y/2
                 x = (x*x) % p; 
             }
             return res;
         }
          
             
         
          
     // Function to comput num (mod a) //for very very large numbers mod computation 
     // ll mymod(string num, ll a)
     // {
     //     // Initialize result
     //     ll res = 0;
      
     //     // One by one process all digits of 'num'
     //     for (ll i = 0; i < num.length(); i++)
     //          res = (res*10 + (ll)num[i] - '0') %a;
      
     //     return res;
     // }
         
         



     





         
         
         
         
         
         //my favourite 
         set<long long> sset;
         map<long long,long long> mapp, b;
         vector<long long> vec;
         
         
         


     // ===============================================================

     // BORUTO AND DOJUTSU ki graph class hai some poriton of chef fib available hai..  
      // isme remove edge compliocated hai but involved kar hi diia because may things are common here. 
      int flag=0;
      // long Y=0;
         ll x=0,y=0;
      // std::set<long> mys;
      // Graph class represents a undirected graph
     // using adjacency list representation
     class Graph
     {
         l V;    // No. of vertices
      
         // Pointer to an array containing adjacency lists
         list<l> *adj;//means array ka har ek index jo hai na vo ek undirected graph ki vertex hai
         // na dit will stores the neighbours of that vertex jo ki uske saath connected hai 
      
         // A function used by DFS
         // void DFSUtil(l v, bool visited[],l color[]);
         void DFSUtil(l v, bool visited[]);
         
     public:
         Graph(l V);   // Constructor
         void addEdge(l v, l w);
         void removeEdge(l v, l w);
         void DFS(l v);        
         // void connectedComponents(l color[]);
     };
      
     // Method to print connected components in an
     // undirected graph
     // void Graph::connectedComponents(l color[])
     // {   
     //     //geeks zindabad 
     //     // Mark all the vertices as not visited
     //     bool *visited = new bool[V];
     //     for(l v = 0; v < V; v++)
     //         visited[v] = false;
      
     //     for (l v=0; v<V; v++)
     //     {
     //         if (visited[v] == false)
     //         {
     //             // print all reachable vertices
     //             // from v
     //             DFSUtil(v, visited,color);//first component 
     //             if(flag==1){ct1(mys.size());flag=0;mys.clear();return ;}
     //             // cout << "\n";
     //             mys.clear();
     //         }
     //     }
     // }
      
     // void Graph::DFSUtil(l v, bool visited[],l color[])
     // {
     //     // Mark the current node as visited and print it
     //     visited[v] = true;
     //     // cout << v << " ";
     //     if(v==Y) {flag=1;}
     //     mys.insert(color[v]);
         
     //     // Recur for all the vertices
     //     // adjacent to this vertex
     //     list<l>::iterator i;
     //     for(i = adj[v].begin(); i != adj[v].end(); ++i)
     //         if(!visited[*i])
     //             DFSUtil(*i, visited,color);
     // }


      
     Graph::Graph(l V)
     {
         this->V = V;
         adj = new list<l>[V];
     }
      
     // method to add an undirected edge
     void Graph::addEdge(l v, l w)
     {
         adj[v].push_back(w);//porblem hai but why !!! ?
         adj[w].push_back(v);//both me push back since it is undirected upar bhi to jana hai isiliye.... 
     }
     void Graph::removeEdge(l v, l w)
     {
         
         //problem
         // long eraser=0;
         list<l>::iterator i;
         // for(i = adj[v].begin(); i != adj[v].end(); ++i)
             // {
                 // if(*i==w) break;
                 // eraser++;
             // }

             // i=adj[v].find(w);
            i = find (adj[v].begin(), adj[v].end(), w); //in map find fucntion is slightly dioffrerner stl is lit  
                        
             // adj[v].erase(adj[v].begin()+eraser);
             adj[v].erase(i);//list is also a dynamic container
             // i self advance ho gya hai just like vectors 

             // $$$$$$$$$$$$$ bi furcation  %%%%%%%%%%%%%%%%%%
         // eraser=0;
         // for(i = adj[w].begin(); i != adj[w].end(); ++i)
         //     {
         //         if(*i==v) break;
         //         // eraser++;
         //     }//we can use find function 
        // i=adj[w].find(v);//log n rather than linear 
        i = find (adj[w].begin(), adj[w].end(), v);
        




         //     // adj[w].erase(adj[w].begin()+eraser);
             adj[w].erase(i);
         
         
         // normal erase functions will not work here 
         // adj[w].pop_back();
     }


         // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ my pure dfs handwritten khud 
         // sse @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ uper wale ko hi update kar dia or extra functions daa ldie bas 
         
      
     void Graph::DFSUtil(l v, bool visited[])
     {
         // Mark the current node as visited and
         // print it
         visited[v] = true;
         // cout << v << " ";
         if(flag==0) x|=vec[v];else y|=vec[v];
         // Recur for all the vertices adjacent
         // to this vertex
         list<l>::iterator i;
         for (i = adj[v].begin(); i != adj[v].end(); ++i)
             if (!visited[*i])
                 DFSUtil(*i, visited);
     }
      

     void Graph::DFS(l v)
     {
         // Mark all the vertices as not visited
         if(flag==0) x=0;else y=0;
         bool *visited = new bool[V];
         for (l i = 0; i < V; i++)
             visited[i] = false;
      
         // Call the recursive helper function
         // to print DFS traversal
         DFSUtil(v, visited);
     }
      









      
      
     //  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  (Works when m and a are coprime) @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
      // Function to find modulo inverse of a using GCD EXTENDED METHOD prereq here must know about HOW GCD EXTENDED ALGO WORKS 
 // void modInverse(ll a, ll m) ////Time Complexity of this method is O(Log m)
 // {
 //     ll x, y; //we use this thign less as always a is not a prime for learning only 
 //     ll g = gcdExtended(a, m, &x, &y);
 //     if (g != 1)
 //         cout << "Inverse doesn't exist";
 //     else
 //     {
 //         // m is added to handle negative x
 //         ll res = (x%m + m) % m;
 //         cout << "Modular multiplicative inverse is " << res;
 //     }
 // }
      
        int isprime(int N){
     if(N<2 || (!(N&1) && N!=2))
         return 0;
     for(int i=3; i*i<=N; i+=2){
         if(!(N%i))
             return 0;
     }
     return 1;
 }


        bool isprime2(int n)
        {
            // Corner cases
            if (n <= 1)  return false;
            if (n <= 3)  return true;
         
            // This is checked so that we can skip 
            // middle five numbers in below loop
            if (n%2 == 0 || n%3 == 0) return false;
         
            for (int i=5; i*i<=n; i=i+6)
                if (n%i == 0 || n%(i+2) == 0)
                   return false;
         
            return true;
        }
         
     
        // IsPrimespecial(i,p)//for the p value that is vile grasshoppers value for finding the mininmal divisor which is > p other than one...  
        bool IsPrimespecial(int x,int p)
        {
            bool flag=true;
            for(int i=2;i<=min(p,(int)sqrt(1.0*x));i++)
            {
                if(x%i==0)
                {
                    flag=false;
                    break;
                }
            }
            return flag;
        }
     
      
      
      
      
      
      
      
           /// FERMATS LITTLE THEOREM BEGIN  (Works when m is prime) which is always t obe irrespective what a is...
 // To compute x raised to power y under modulo m   O(Log m)
 ll expower(ll x, ll y, ll m);
  
 // Function to find modular inverse of a under modulo m
 // Assumption: m is prime
 ll modInverse(ll a, ll m)
 {
 ll g = gcd(a, m);
 if (g != 1){}
     // cout << "Inverse doesn't exist";
  
 else
 {
     // If a and m are relatively prime, then modulo inverse
     // is a^(m-2) mode m
     // cout << "Modular multiplicative inverse is "
          return expower(a, m-2, m);
 }
 }
  
 // To compute x^y under modulo m in o(logy) recursive modualr exponentiation 
 ll expower(ll x, ll y, ll m)
 {
 if (y == 0)
     return 1;
 ll p = expower(x, y/2, m) % m;
 p = (p * p) % m;
  
 return (y%2 == 0)? p : (x * p) % m;
 }
  
      
      
      
      
      
      
  
 // void simplify_fraction(int num, int denom)
 // {
 //  for (int i = denom; i>=2; i--)
 //  {
 //   if (num % i == 0 && denom % i == 0)
 //   {
 //   num = num/i;
 //   denom = denom/i;
 //   }
 //  }
 //  cout << "Fraction: ";
 //  if (denom == 1)
 //   cout << num;
 //  else
 //   cout << num << "/" << denom;
 //  cout << endl;
 // }
  
  
      
      
      
      
     //  very powerful for handling negative values 
     // ll mymod(ll ans,ll NUM12) 
     // {return ( (ans % NUM12 + NUM12) % NUM12);}//version 1 
     ll mymod (ll m, ll n) { return m >= 0 ? m % n : ( n - abs ( m%n ) ) % n; }//version 2
     
     
     
 //      ll foo(long double a)
 // {
 //     double integral = std::floor(input);
 //     double frac = input - integral;
  
 //     const long precision = 1000000000; // This is the accuracy.
  
 //     long gcd_ = gcd(round(frac * precision), precision);
  
 //     long denominator = precision / gcd_;
 //     long numerator = round(frac * precision) / gcd_;
  
 //     // std::cout << integral << " + ";
 //     std::cout << numerator << " / " << denominator << std::endl;
 //     return (modInverse(denominator,NUM));
 //     // return ((numerator*modInverse(denominator,NUM)) mod NUM); //definilt overflow very large nos 
     
 //  double fractional_part = number - floor(number);
  
 //  for (double i = 0.1, j = 10;  ; i/=10, j*=10)
 //  {
 //   if ( fractional_part >= i )
 //   {
 //   simplify_fraction(number * j, j);
 //   break;
 //   }
 //  }
  
 // 101% code for fractional not for rational ex 0.5000000000 
 //     long long int c = 1000000000;
 //     long double b = (a - floor(a)) * c;
 //     long long int d = (ll)floor(a) * c + (ll)(b + .5f); 
 //     // printf("%f %d\n", b, d);
  
 //     while(1) {
 //       if(d % 10 == 0) {
 //           d = d / 10;
 //           c = c / 10;
 //       }
 //       else break;
 //     }
 //     printf("%lld/%lld\n", d, c);// d num c deno
 //     exit(0);    
 //     ll ans = (((modInverse(c,NUM))%NUM)*(mymod(d,NUM)))%NUM;
 //     return ans;
  
     
 // }
      
      
      
      
  
     //handle with carreful ness 
  
  
  
 //  void rat_approx(long double f, ll md, ll *num, ll *denom)
 // {
 //  /*  a: continued fraction coefficients. */
 //  ll a, h[3] = { 0, 1, 0 }, k[3] = { 1, 0, 0 };
 //  ll x, d, n = 1;
 //  ll i, neg = 0;
  
 //  if (md <= 1) { *denom = 1; *num = (ll) f; return; }
  
 //  if (f < 0) { neg = 1; f = -f; }
  
 //  while (f != floor(f)) { n <<= 1; f *= 2; }
 //  d = f;
  
 //  /* continued fraction and check denominator each step */
 //  for (i = 0; i < 64; i++) {
 //      a = n ? d / n : 0;
 //      if (i && !a) break;
  
 //      x = d; d = n; n = x % n;
  
 //      x = a;
 //      if (k[1] * a + k[0] >= md) {
 //          x = (md - k[0]) / k[1];
 //          if (x * 2 >= a || k[1] >= md)
 //              i = 65;
 //          else
 //              break;
 //      }
  
 //      h[2] = x * h[1] + h[0]; h[0] = h[1]; h[1] = h[2];
 //      k[2] = x * k[1] + k[0]; k[0] = k[1]; k[1] = k[2];
 //  }
 //  *denom = k[1];
 //  *num = neg ? -h[1] : h[1];
 // }
     
     
     
     
 // to compute (a*b)%mod even when then numbers are negative /coding knight zindabad 
 // ll mulmod( ll a, ll b, const ll c )
 // {
 //     assert( c > 0 );//for runtime abortion of the case wehn modulo < 0 
  
 //     ll y = 0; bool negative = false;
  
 //     if ( a < 0 )
 //         a = -a, negative = !negative;
  
 //     if ( b < 0 )
 //         b = -b, negative = !negative;
  
 //     if ( a < b )
 //         swap( a, b );
  
 //     for ( a %= c; b; a <<= 1, b >>= 1, a %= c )
 //             if ( b & 1 )
 //                 y += a, y %= c;
  
 //     return negative ? ( c - y ) : y;
 // }
  
     
     
     
     
 //normal a*b under mod

   
 // To compute (a * b) % mod
 ll mulmod(ll a, ll b, ll mod)
 {
     ll res = 0; // Initialize result
     a = a % mod;
     while (b > 0)
     {
         // If b is odd, add 'a' to result
         if (b % 2 == 1)
             res = (res + a) % mod;
  
         // Multiply 'a' with 2
         a = (a * 2) % mod;
  
         // Divide b by 2
         b /= 2;
     }
  
     // Return result
     return res % mod;
 }
     
     
     
     

  
 // To compute (a * b) % mod
 // __int128 mulmodnego(__int128 a, __int128 b, __int128 mod)
 // {
 //     __int128 res = 0; // Initialize result
 //     a = a % mod;
 //     while (b > 0)
 //     {
 //         // If b is odd, add 'a' to result
 //         if (b % 2 == 1)
 //             res = (res + a) % mod;
  
 //         // Multiply 'a' with 2
 //         a = (a * 2) % mod;
  
 //         // Divide b by 2
 //         b /= 2;
 //     }
  
 //     // Return result
 //     return res % mod;
 // }
      
      
      
      
      //v imp log function 
      ll Logn(ll n, ll r)// this is in O(1)time with auxillary space of O(1)
     {
        return log(n) / log(r);
     }
      
      
      
      
      
      
      
      
         //everything new must be defined below 
         //reucrsive functions here 
      
         ll func(ll a ){
             ll prod=1;
             while(a>0){if(a%10!=0)prod*=a%10;a/=10;}
             return prod;
         }
             
         ll check(ll a){
             if(a<10) return a;
             return check(func(a));
         }
             
             
      
      
      
      
      
      
      
      
      
      
      
      
      
      
         
 //     int x[10][1000005];//by default values are 0 initially 
     
      
      //recursive queries lakh and jacqueen ka dhamaka heere..
      
 //         void solveit(){
 //  for(int i=1;i<=1000000;i++){
 //      x[check(i)][i]++;
 //  }
 //  for(int i=1;i<10;i++){
 //      for(int j=1;j<=1000000;j++){
 //          x[i][j]+=x[i][j-1];
 //      }
 //  }
 //  int Q;
 //  cin>>Q;
 //  while(Q--){
 //      int left,r,k;
 //      cin>>left>>r>>k;
 //      cout<<x[k][r]-x[k][left-1]<<endl;
 //  }
 // }

      
      
      
      // C++ program to count triplets with given 
 // product m

 // // Function to count such triplets
 // int countTriplets(int arr[], int n, int m)
 // {
 //     // Store all the elements in a set
 //     unordered_map<int, int> occ;
 //     for (int i = 0; i < n; i++)
 //         occ[arr[i]] = i;
  
 //     int count = 0;
  
 //     // Consider all pairs and check for a
 //     // third number so their product is equal to m
 //     for (int i = 0; i < n - 1; i++)
 //     { 
 //         for (int j = i + 1; j < n; j++)
 //         {
 //             // Check if current pair divides m or not
 //             // If yes, then search for (m / arr[i]*arr[j])
 //             if ((arr[i] * arr[j] <= m) && 
 //                 (arr[i] * arr[j] != 0) && 
 //                 (m % (arr[i] * arr[j]) == 0)) 
 //             {
 //                 int check = m / (arr[i] * arr[j]);
 //                 auto it = occ.find(check);
  
 //                 // Check if the third number is present
 //                 // in the map and it is not equal to any
 //                 // other two elements and also check if
 //                 // this triplet is not counted already
 //                 // using their indexes
 //                 if (check != arr[i] && check != arr[j]
 //                     && it != occ.end() && it->second > i
 //                     && it->second > j)
 //                     count++;
 //             }
 //         }
 //     }
  
 //     // Return number of triplets
 //     return count;
 // }


         //define functions here 



     
         ll findf(l factor){ll facto=1;
 while(factor!=1){
                     facto*=factor;factor--;
                 }
                 return facto;
         }
                 
        
        //  l mybsearch(vector<pair<l,l>> a,l element,l low,l high){
          l mybsearchperfect(l element,l low,l high){//accurate wali on an global vector or array bhi pass kar sakte ho here.....  
                
             if(low>high) return -1;
             l mid=(low+high)/2;
             if(vec[mid]==element) return mid;
             if(element>vec[mid]) return mybsearchperfect(element,mid+1,high);
             else return mybsearchperfect(element,low,mid-1);
         }



         
         l mybsearch(vector<pair<l,l>> a,l element,l low,l high){
             if(low>=high) return -1;
             l mid=(low+high)/2;
             if(a[mid].first==element) return mid;
             if(element>a[mid].first) return mybsearch(a,element,mid+1,high);
             else return mybsearch(a,element,low,mid);


         }


     //ye accurate tedhi binary search hai but use lower_bound upper_bound in case of this vo iska bhi baap hai..
     ll mybsearch2(ll a[],ll element,ll low,ll high){
         ll mid=(low+high)/2;
         if(a[mid]==element) return mid;
         
         
         // if(element>a[mid]) return mid;
         if(low>=high) return -1;
         if(element>a[mid]) return mybsearch2(a,element,mid+1,high);
         else return mybsearch2(a,element,low,mid);
     }







         #define llmaxd LONG_LONG_MAX //used when u want to replace INT_MAX
         #define llmind LONG_LONG_MIN //used when u want to replace INT_MAX
      
         // int count( int S[], int m, int n )
         // {
         //     int i, j, x, y,mino,maxo;
          
         //     // We need n+1 rows as the table is constructed 
         //     // in bottom up manner using the base case 0
         //     // value case (n = 0)
         //     int table[n+1][m];
             
         //     // Fill the enteries for 0 value case (n = 0)
         //     for (i=0; i<m; i++)
         //         table[0][i] = 1;
          
         //     // Fill rest of the table entries in bottom 
         //     // up manner  
         //     for (i = 1; i < n+1; i++)
         //     {
         //         mino=INT_MAX,maxo=INT_MIN;
         //         for (j = 0; j < m; j++)
         //         {
         //             // Count of solutions including S[j]
         //             x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
         //             if(x!=0){
         //                 mino=min(mino,i/S[j]);
         //                 maxo=mino;
         //             }
                         

         //             // Count of solutions excluding S[j]
         //             y = (j >= 1)? table[i][j-1]: 0;
         //             // if(y!=0) mino=min(mino,y);
         //             // total count
         //             table[i][j] = x + y;
         //             if(j==0&&(x+y)!=0){
         //                 mino=min(mino,i/S[j]);
         //                 maxo=mino;continue;
         //             } 
         //             if(x+y==0&&j==m-1){mino=-1,maxo=-1;}else if(x+y==0&&j!=m-1){
         //           mino=INT_MAX,maxo=INT_MIN;
                         

         //             } 
         //             else {
         //             maxo=max(maxo,x+y);                                                
         //             // mino=min(mino,x+y);
         //             mino=maxo;
         //         }
         //         }
         //     }
         //     cout<<mino<<" "<<maxo;
         //     // return table[n][m-1];
         // }
          

     



























         //ye graph class meri main se pehle hi rheggi hamesha here 

         // ========================= to check whether path exist between two nodes of 
         // an undirected or an directed graph @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  
         
         // // C++ program to check if there is exist a path between two vertices
         // // of a graph.
         
          
         // // This class represents a directed graph using adjacency list 
         // // representation
         // class Graph
         // {
         //     int V;    // No. of vertices
         //     list<int> *adj;    // Pointer to an array containing adjacency lists
         // public:
         //     Graph(int V);  // Constructor
         //     void addEdge(int v, int w); // function to add an edge to graph
         //     bool isReachable(int s, int d);  
         // };
          
         // Graph::Graph(int V)
         // {
         //     this->V = V;
         //     adj = new list<int>[V];
         // }
          
         // void Graph::addEdge(int v, int w)
         // {
         //     adj[v].push_back(w); // Add w to v’s list.
         // }
          
         // // A BFS based function to check whether d is reachable from s.
         // bool Graph::isReachable(int s, int d)
         // {
         //     // Base case
         //     if (s == d)
         //       return true;
          
         //     // Mark all the vertices as not visited
         //     bool *visited = new bool[V];
         //     for (int i = 0; i < V; i++)
         //         visited[i] = false;
          
         //     // Create a queue for BFS
         //     list<int> queue;
          
         //     // Mark the current node as visited and enqueue it
         //     visited[s] = true;
         //     queue.push_back(s);
          
         //     // it will be used to get all adjacent vertices of a vertex
         //     list<int>::iterator i;
          
         //     while (!queue.empty())
         //     {
         //         // Dequeue a vertex from queue and print it
         //         s = queue.front();
         //         queue.pop_front();
          
         //         // Get all adjacent vertices of the dequeued vertex s
         //         // If a adjacent has not been visited, then mark it visited
         //         // and enqueue it
         //         for (i = adj[s].begin(); i != adj[s].end(); ++i)
         //         {
         //             // If this adjacent node is the destination node, then 
         //             // return true
         //             if (*i == d)
         //                 return true;
          
         //             // Else, continue to do BFS
         //             if (!visited[*i])
         //             {
         //                 visited[*i] = true;
         //                 queue.push_back(*i);
         //             }
         //         }
         //     }
              
         //     // If BFS is complete without visiting d
         //     return false;
         // }
          
         // // Driver program to test methods of graph class
         // int main()
         // {

                 // $$$$$$$$$$$$$//has bas iske main ko modify kar
                 // dena##################### 


         //     // Create a graph given in the above diagram
         //     int n,m,q;
         //     std::cin >> n>>m;
         //     Graph g(n);
         //     int u = 0, v = 0;
         //     for(int i=0;i<m;i++){
         //         std::cin >> u>>v;
         //     g.addEdge(u-1, v-1);
         //     g.addEdge(v-1, u-1);
         //     // g.addEdge(1, 3);
         //     // g.addEdge(3, 1);
             
         //     }
         //     // g.addEdge(2, 3);
         //     // g.addEdge(3, 3);
          
         //     std::cin >> q;
         //     while(q--){
         //         std::cin >> u>>v;
         //         u--;v--;
         //     if(g.isReachable(u, v))
         //         // cout<< "\n There is a path from " << u << " to " << v;
         //         cout<<"YES"<<"\n";
         //     else
         //         cout<<"NO"<<"\n";
         //         // cout<< "\n There is no path from " << u << " to " << v;
          
         //     // u = 3, v = 1;
         //     // if(g.isReachable(u, v))
         //     //     cout<< "\n There is a path from " << u << " to " << v;
         //     // else
         //     //     cout<< "\n There is no path from " << u << " to " << v;
         //     }
         //     return 0;
         // }

     
         
     

         //very important bit tactics ....... %%%%%%%%%%%%%%%%

         
          ll takemod(ll num)//for also handling the negative numbers but it is not accepting the solution...  ye pradanya ka kammaal tha... 
             {
                 if(num<0)
                     num+=mod;
                 num=num%mod;
                 return num;
             }
          

          ll toggleKthBit(ll n, ll k)
          {
              return (n ^ (1 << (k-1)));
          }

          // This function swaps bit at positions p1 and p2 in an integer n
          ll swapBits(ll n, ll p1, ll p2)
          {
              /* Move p1'th to rightmost side */
              ll bit1 =  (n >> p1) & 1;
           
              /* Move p2'th to rightmost side */
              ll bit2 =  (n >> p2) & 1;
           
              /* XOR the two bits */
              ll x = (bit1 ^ bit2);
           
              /* Put the xor bit back to their original positions */
              x = (x << p1) | (x << p2);
           
              /* XOR 'x' with the original number so that the
                 two sets are swapped */
              ll result = n ^ x;
              return result;
          }


          ll setKthBit(ll n, ll k)
          {
              // kth bit of n is being set by this operation
              return ((1 << k) | n);
          }
          ll turnOffK(ll n, ll k)
          {
              // k must be greater than 0
              if (k <= 0) return n;
           
              // Do & of n with a number with all set bits except
              // the k'th bit
              return (n & ~(1 << (k - 1)));
          }


          // function to toggle bits in the given range
  
          // unsigned long long toggleBitsFromLToR(unsigned ll n,unsigned ll left, unsigned 
          //    ll right)
          // {
          //     // calculating a number 'num' having 'r'
          //     // number of bits and bits in the range l
          //     // to r are the only set bits
          //     ll number = ((1 << right) - 1) ^ ((1 << (left - 1)) - 1);
           
          //     // toggle bits in the range l to r in 'n'
          //     // and return the number
          //     return (n ^ number);
          // }



         //here dp matrix table ka size wihtin range 10^5 tak hona chhaiye and ques me sum to 0 se 10^18 tak ja rha tha na.... 

         // Returns true if there is a subset of set[] with sun equal to given sum
         // bool isSubsetSum(std::vector<ll> locvec, ll n, ll sum)
         // {
         //     // The value of subset[i][j] will be true if there is a 
         //     // subset of set[0..j-1] with sum equal to i
         //     bool subset[n+1][sum+1];
           
         //     // If sum is 0, then answer is true
         //     for (ll i = 0; i <= n; i++)
         //       subset[i][0] = true;
           
         //     // If sum is not 0 and set is empty, then answer is false
         //     for (ll i = 1; i <= sum; i++)
         //       subset[0][i] = false;

           
         //      // Fill the subset table in botton up manner
         //      for (ll i = 1; i <= n; i++)
         //      {
         //        for (ll j = 1; j <= sum; j++)
         //        {
         //          if(j<set[i-1])
         //          subset[i][j] = subset[i-1][j];
         //          if (j >= set[i-1])
         //            subset[i][j] = subset[i-1][j] || 
         //                                  subset[i - 1][j-set[i-1]];
         //        }
         //      }
           
         //      /*   // uncomment this code to print table
         //      for (int i = 0; i <= n; i++)
         //      {
         //        for (int j = 0; j <= sum; j++)
         //           printf ("%4d", subset[i][j]);//or %I64_d we can use this 
         //        printf("n");
         //      }*/
           
         //      return subset[n][sum];
         // }
     



         // bool SieveOfSundaram(std::vector<ll> locvec,ll n,ll m)
         // {
         //     // In general Sieve of Sundaram, produces primes smaller
         //     // than (2*x + 2) for a number given number x.
         //     // Since we want primes smaller than n, we reduce n to half
         //     ll nNew = (n-2)/2;
          
         //     // This array is used to separate numbers of the form i+j+2ij
         //     // from others where  1 <= i <= j
         //     bool marked[nNew + 1];
             
         //     // Initalize all elements as not marked
         //     memset(marked, false, sizeof(marked));
          
         //     // Main logic of Sundaram.  Mark all numbers of the
         //     // form i + j + 2ij as true where 1 <= i <= j
         //     for (ll i=1; i<=nNew; i++)
         //         for (ll j=i; (i + j + 2*i*j) <= nNew; j++)
         //             marked[i + j + 2*i*j] = true;
          
         //     // Since 2 is a prime number
         //     if (n > 2){
         //         // cout << 2 << " ";
         //         if(isSubsetSum(locvec,n,2)&&isSubsetSum(locvec,n,2+m)) {ct1("YES");return true;}
                 


         //     }
          
         //     // Print other primes. Remaining primes are of the form
         //     // 2*i + 1 such that marked[i] is false.
         //     for (ll i=1; i<=nNew; i++){
         //         if (marked[i] == false){
         //             // cout << 2*i + 1 << " ";
         //             if(isSubsetSum(locvec,n,2*i + 1)&&isSubsetSum(locvec,n,2*i + 1+m)) {ct1("YES");return true;}

         //         }}
         //         return false;
         // }
         





                       
                         
                         
       long long C(int n, int r) {//but yha pe na 0 bhi include ho jata //here this is an combination function.. 
             if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
             long long ans = 1;
             int i;
          
             for(i = 1; i <= r; i++) {
                 ans *= n - r + i;
                 ans /= i;
             }
          
             return ans;
       }
          

        


        float rounded(float var){
            // 37.66666 * 100 =3766.66
            // 3766.66 + .5 =37.6716    for rounding off value
            // then type cast to int so value is 3766
            // then divided by 100 so the value converted into 37.66
            float value = (int)(var * 100 + .5);
            return (float)value / 100;
        }


           
           
       //     //this is rhyming by the way.. 
       //  bool check(string a,string b){
       //      int flag=1,i=0;
       //      for (i = a.size()-1; i >= 0; i--) {
       //          /* code */
       //          if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){ flag=0;break;}
       //      }
       //      if(flag==1) return false;
       //      flag=1;
       //      for (int ii = b.size()-1; ii >= 0; ii--) {
       //          /* code */
       //          if(b[ii]=='a'||b[ii]=='e'
       //          ||b[ii]=='i'||b[ii]=='o'||b[ii]=='u'){ 
                    
       //          if(b[ii]==a[i]) {flag=0;break;}
       //          else break;     
                    
       //          }
                
       //      }
       //      if(flag==1) return  false;
       //      else if(flag==0) return true;
       //  }
           
       /* 

        ld globtimer=0;
        bool checky(ld v[],ld c[],int d[],ld pos[],int ii,ld diff,ld S,int n,int y){
            // for that lane only..
            // for(int i=ii;i<=n;i++) {
            if(ii==n+1) return true;//base case..
            int i=ii;
            // ct1(i);
            ld timer=0;
            if(d[i]==1){

                if(pos[i]-c[i]>=0){
                ld chef = y/(ld)(S);//yha confuson hai check once 
                timer+=chef;
                 if(diff!=-1) return true;//for checking     
                }

                    else {

                        if(pos[i]<0){
                            // ct1("hello");
                ld timnecar = (abs(pos[i]-0))/(ld)(v[i]);
                ld chef = y/(ld)(S);
                    // ct2("timecar",timnecar);
                            // exit(0);
                
                if(chef>=timnecar) {//yha cahnge kiya hai tab distacne 10^-6 se kam hoga 
                    timnecar=(abs(pos[i]-c[i]))/(ld)(v[i]);
                    if(diff!=-1) {
                        if(diff<=timnecar) {return false;} else {}
                    }
                    timer+=timnecar+chef;
                }



                // else timer+=chef;//main yha pe calc hai funciton wali  ye optimal haio 
                else if(pos[i]+(chef*v[i]) > 0.000001) {
                    //phir yha greedily sohco jane ka 
                    FJ2(n){
                        //update cars positions 
                        if(d[j]==1){
                            pos[j]+=(chef*v[j]);
                        }
                        else {
                            pos[j]-=(chef*v[j]);


                        }
                    }

                if(checky(v,c,d,pos,i+1,timnecar-chef,S,n,y)) {
                timer+=chef;globtimer+=timer;return true;
                //continue;
                }
                else {
                    FJ2(n){
                        //re-update cars positions 
                        if(d[j]==1){
                            pos[j]-=(chef*v[j]);
                        }
                        else {
                            pos[j]+=(chef*v[j]);


                        }
                    }//reupdte the positions 

                    timnecar=(abs(pos[i]-c[i]))/(ld)(v[i]);
                    if(diff!=-1) {
                        if(diff<=timnecar) {return false;} else {}
                    }
                    timer+=timnecar+chef;
                    
                }
                } 


                else {//wait karvao yrr 

                    timnecar=(abs(pos[i]-c[i]))/(ld)(v[i]);
                    if(diff!=-1) {
                        if(diff<=timnecar) {return false;} else {}
                    }
                    timer+=timnecar+chef;
                    
                    }


            }

            else {//yha 2 case handle karoge 
                ld timnecar = (abs(pos[i]-c[i]))/(ld)(v[i]);
                ld chef = y/(ld)(S);
                
                // if(chef>timnecar) {
                    // timnecar=(abs(pos[i]-c[i]))/(ld)(v[i]);
                    if(diff!=-1) {
                        if(diff<=timnecar) {return false;}else {}
                    }
                    timer+=timnecar+chef;
                // }
                // else timer+=chef;                        
            }


            }

            }   



            else {
                    if(pos[i]+c[i]<=0){
                    ld chef = y/(ld)(S);
                    timer+=chef;
                        if(diff!=-1) return true;//for checking     
                        
                    }
                        else {

                            if(pos[i]>0){
                    ld timnecar = (abs(pos[i]-0))/(ld)(v[i]);
                    ld chef = y/(ld)(S);
                    
                    if(chef>=timnecar) {
                        timnecar=(abs(pos[i]+c[i]))/(ld)(v[i]);
                        if(diff!=-1) {
                            if(diff<=timnecar) {return false;}else {}
                        }
                        timer+=timnecar+chef;
                    }

                    else if(pos[i]-(chef*v[i]) > 0.000001) {

                        FJ2(n){
                            //update cars positions 
                            if(d[j]==1){
                                pos[j]+=(chef*v[j]);
                            }
                            else {
                                pos[j]-=(chef*v[j]);


                            }
                        }

                    if(checky(v,c,d,pos,i+1,timnecar-chef,S,n,y)) {timer+=chef;
                    globtimer+=timer;return true;
                    // globtimer+=timer;//continue;
                    }
                    else {
                        FJ2(n){
                            //update cars positions 
                            if(d[j]==1){
                                pos[j]-=(chef*v[j]);
                            }
                            else {
                                pos[j]+=(chef*v[j]);


                            }
                        }//reupdte the positions 

                        timnecar=(abs(pos[i]+c[i]))/(ld)(v[i]);
                        if(diff!=-1) {
                            if(diff<=timnecar) {return false;}else {}
                        }
                        timer+=timnecar+chef;
                        
                    }
                    } 

                    else {


                        timnecar=(abs(pos[i]+c[i]))/(ld)(v[i]);
                        if(diff!=-1) {
                            if(diff<=timnecar) {return false;}else {}
                        }
                        timer+=timnecar+chef;



                    }

                }

                else {
                    ld timnecar = (abs(pos[i]+c[i]))/(ld)(v[i]);
                    ld chef = y/(ld)(S);
                    // if(pos[i]==0){}
                        // else { //yha add kar do 
                    // if(chef>=timnecar) {
                        timnecar=(abs(pos[i]+c[i]))/(ld)(v[i]);
                        if(diff!=-1) {
                            if(diff<=timnecar) {return false;}else {}
                        }
                        timer+=timnecar+chef;
                    // }
                    // else timer+=chef;
                    // }                        
                }


                }




            }

            globtimer+=timer;//here mistake ho rhi hai 
            // ct1(timer);
            FJ2(n){
                //update cars positions 
                if(d[j]==1){
                    pos[j]+=(timer*v[j]);
                }
                else {
                    pos[j]-=(timer*v[j]);


                }


            }
            checky(v,c,d,pos,i+1,-1,S,n,y);//-1 means arbitrarily long wait 


        // }

        return true;



        //samjkh zroor lena agar  mouka lage toh 

        }
    */
        // Returns maximum sum in a subarray of size k. // no need here some problem comes here.. 
       //  ll maxSum(std::vector<pair<ll,pair<ll,ll>> > myv
       //          , ll n, ll k,ll coins[])
       //  {
       //      // k must be greater
       //      // if (n < k)
       //      // {
       //      //    cout << "Invalid";
       //      //    return -1;
       //      // }
         
       //      // Compute sum of first window of size k
       //      ll res = 0;
       // //      for (ll i=0; i<k; i++)
       // //         // res += arr[i];
       // //     // res+=coins[myv[i].second.second];
       // // res+=myv[i].second.first;
         
       // //      // Compute sums of remaining windows by
       // //      // removing first element of previous
       // //      // window and adding last element of 
       // //      // current window.
       // //      ll curr_sum = res;
       // //      for (ll i=k; i<n; i++)
       // //      {
       // //          // arr[i] - arr[i-k];
       // //          // curr_sum += coins[myv[i].second.second]-coins[myv[i-k].second.second];
       // //          curr_sum += myv[i].second.first-myv[i-k].second.first;
       // //          res = max(res, curr_sum);
       // //      }
         

       //          ll test[n];
       //          for (ll j = 0; j < n; ++j)
       //          {
       //              /* code */

       //              test[j]=myv[j].second.first;
       //          }

       //          sort(test,test+n);
       //          ll tester=0;
       //                          for (ll ki = n-1; ki>=  0; ki--)
       //          {
       //              /* code */
       //              res+=test[ki];
       //              tester++;
       //              if(tester==k) break;
       //          }


       //      return res;
       //  }


        ll bill=0;
        void findbill(ll no){
            if(no==0) return;
            if (no<100)
            {
                /* code */
                if (no>=20)
                {
                    /* code */
                    bill+=no/20;
                    findbill(no%20);
                }
                else {
                    if(no>=10){
                        bill+=no/10;
                        findbill(no%10);
                                

                    }
                    else {
                        if(no>=5){
                            bill+=no/5;
                            findbill(no%5);
                            
                        }
                        else {
                            if(no>=1){
                                bill+=no/1;
                                findbill(no%1);
                                
                            }
                            else {}//min no is 1

                        }
                    }
                }
            }
            else {

                bill+=no/100;findbill(no%100);

            }
            

        }



         //ab xxor to kar ke hi saans lunga kar dia 
       
        // ================================================
      
         int32_t main(int argc, char** argv) {
            
         ios_base::sync_with_stdio(0);cin.tie(0);
         #ifdef LOCAL
                   FREIN("input.txt");
                   // FREOUT("out.txt"); 
         #endif
      
         //for weak judges sometimes upper thing gives an slow execution so use below 
      
         // #ifndef ONLINE_JUDGE 
         //     freopen("input.txt","r",stdin);
         //     freopen("output2.txt","w",stdout);
         // #endif
      
      
             return solve();
         }
        int32_t solve(){
            //ios::base::sync_with_sdtio(false),cin.tie(nullptr);
            //  Broken CLOCKS_PER_SEC
            //UNION FIND ALGORITHM
            //FOR DISJOINT SET UNION OR DISJOINT SET DATA STRUCTURES 
            int t;ll n=0,h=0,m=0,k=0,q=0,maxsum=llmind,minsum=llmaxd,left,right;
            // ci3(n,k,m);
            // ci1(t);
            bool flag=false;
            ll x,y;int count=0,a,b,c,exa=0,exb=0;
            // ci4(a,b,c,n);
            ci1(n);
            bill=0;
            // if (n<100)
            // {
            //     /* code */



            // }
            // else {
            //     bill+=n/100+func(n%100)

            // }
            findbill(n);
            ct1(bill);

















            // if(c==0&&a+b>=n)
            // {
            //     /* code */
            //     ct1(-1);
            // }
            // else if(c==0) 
            // {
            //     /* code */
            //     if(n<=a||n<=b){
            //         ct1(-1);

            //     }
            //     else {
            //         ct1(n-(a+b));

            //     }
            // }
            






            
            //     else {//when c is not zero 


            //         if(c>a||c>b||c>=n) {ct1(-1);exit(0);}//bas yhi miss kar gya yrr kyuuuuuuunnnnnn



            //         if(n<=c||n<=a||n<=b||(n<=a+(b-c))) {
            //             ct1(-1);

            //         }
            //         else {
            //             exa=a-c,exb=b-c;
            //         if(n<=exa||n<=exb||n<=(exa+exb+c)){
            //             ct1(-1);
            //         }
            //         else {
            //             ct1(n-(exa+exb+c));//bache hue students includind vasya which are at home 

            //         }
            //     }
            //     }

            
           


            // ct1(count);







            return 0;
        }
