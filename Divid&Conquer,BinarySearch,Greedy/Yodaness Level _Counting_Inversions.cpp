#include <bits/stdc++.h>
using namespace std;
								/* This is an important emample
								 * of binary indexed tree (BIT)
//using counting inversions				 * Also another solving approach is 
								 * merge sort/counting inversions*/
vector<string>v1;
map<string,int>mp;
int arr[100000],cnt;

void merge(int l,int m,int r)
{
    int i,j,k,n1,n2;
    n1=m-l+1;
    n2=r-m;
    long long int b[n1],c[n2];
    
    for(i=0;i<n1;i++)
    {
        b[i]=arr[l+i];
    }
    for(j=0;j<n2;j++)
    {
        c[j]=arr[m+1+j];
    }
    i=0; 
    j=0; 
    k=l; 
    while(i<n1 && j<n2)
    {
        if(b[i]<=c[j])
        {
            arr[k]=b[i];
            i++;
        }
        else
        {
            arr[k]=c[j];
            j++;
            cnt+=n1-i;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=b[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=c[j];
        j++;
        k++;
    }
}

void mergeSort(int l,int r)
{
    int m;
    if(l<r)
    {
        m=l+(r-l)/2;
        mergeSort(l,m);
        mergeSort(m+1,r);
        merge(l,m,r);
    }
}



int main()
{
	int test,n;
	string str;
	
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		cnt=0;
		
		for(int i=0;i<n;i++) 
		{
			cin>>str;
			v1.push_back(str);
		}
		for(int i=0;i<n;i++)
		{
			cin>>str;
			mp[str] = i+1;
		}
		for(int i=0;i<n;i++)
		{
			arr[i]=mp[v1[i]];
		}
		mergeSort(0,n-1);
	
		printf("%d\n",cnt);
		v1.clear();
		mp.clear();
	}
	
	return 0;
}

