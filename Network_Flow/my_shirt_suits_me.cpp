#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long
using namespace std;
 
struct volunteer {
    char choice1 [10];
    char choice2 [10];
} v [30 + 5];
 
int shirt_avail [6 + 3];
int n, m;
bool solution;
 
void reset (int p)
{
    for ( int i = 0; i < 9; i++ )
        shirt_avail [i] = p;
}
 
int shirt_index (char *k)
{
    if ( strcmp (k, "XXL") == 0 ) return 0;
    if ( strcmp (k, "XL") == 0 ) return 1;
    if ( strcmp (k, "L") == 0 ) return 2;
    if ( strcmp (k, "M") == 0 ) return 3;
    if ( strcmp (k, "S") == 0 ) return 4;
    return 5;
 
}
 
void bktk (int p)
{
    if ( p == m ) { solution = true; return; }
    if ( solution == true ) return;
 
    if ( shirt_avail [shirt_index (v [p].choice1)] ) {
        shirt_avail [shirt_index (v [p].choice1)]--;
        bktk (p + 1);
        shirt_avail [shirt_index (v [p].choice1)]++;
    }
    if ( shirt_avail [shirt_index (v [p].choice2)] ) {
        shirt_avail [shirt_index (v [p].choice2)]--;
        bktk (p + 1);
        shirt_avail [shirt_index (v [p].choice2)]++;
    }
}
 
int main ()
{
    int testCase;
    scanf ("%d", &testCase);
 
    while ( testCase-- ) {
        scanf ("%d %d", &n, &m);
 
        for ( int i = 0; i < m; i++ ) scanf ("%s %s", v [i].choice1, v [i].choice2);
 
        reset (n / 6);
 
        solution = false;
        bktk (0);
 
        if ( solution ) printf ("YES\n");
        else printf ("NO\n");
    }
 
    return 0;
}
