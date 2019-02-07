#include <bits/stdc++.h>
using namespace std;

bool comp(int x,int y)
{
    return x>y;
}

int main() 
{
    int n,m,k,t;

    scanf("%d%d",&n,&m);
    int ar[111111],br[111111];
    t=m/n;
    int nn=n;
    if(t==0)
    {
		cout<<t<<endl;
		return 0;
	}
   
    for(int i=0;i<m;i++)
    {
        cin>>ar[i];
    }
    
    sort(ar,ar+m);
    
    int c=1;
    k=0;
    for(int j=1;j<m;j++)
    {
         if(ar[j]==ar[j-1])
         {
             c++;
         }
         else 
         {
             br[k++]=c;c=1;
         }
    }
    
    br[k++]=c;
    int t1=t;
    sort(br,br+k,comp);
    
    while(t1)
    {
        nn=n;t=t1;
        for(int i=0;i<k && t>0;i++)
        {
            if(br[i]>=t)
            {
                nn-=(br[i]/t);
            }
            if(nn<=0) 
            {
				cout<<t<<endl;
				return 0;
			}
        }
        t1--;
    }
    
	return 0;
}
