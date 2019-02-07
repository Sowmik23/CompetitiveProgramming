#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int> 
#define INF 1000000

int coins[] =  {2,3,4,5,6,7}; 
int m =6;
 
int minCoins(int coins[], int m, int V) 
{ 
    int table[V+1]; 
 
    table[0] = 0; 
  
    for (int i=1; i<=V; i++) 
        table[i] = INT_MAX; 
  

    for (int i=1; i<=V; i++) 
    { 
        for (int j=0; j<m; j++) 
          if (coins[j] <= i) 
          { 
              int sub_res = table[i-coins[j]]; 
              if (sub_res != INT_MAX && sub_res + 1 < table[i]) 
                  table[i] = sub_res + 1; 
          } 
    } 
    return table[V]; 
} 

int main() 
{ 
    int t,V;
    scanf("%d",&t);
    while(t--)
    {
		scanf("%d",&V);
 
        printf("%d\n",minCoins(coins, m, V)); 
	}
	
    return 0; 
} 
