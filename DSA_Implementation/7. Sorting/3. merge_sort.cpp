#include<stdio.h>
 
void merge(long long int a[],int l,int m,int r)
{
    int i,j,k,n1,n2;
    n1=m-l+1;
    n2=r-m;
    long long int b[n1],c[n2];
    
    for(i=0;i<n1;i++)
    {
        b[i]=a[l+i];
    }
    for(j=0;j<n2;j++)
    {
        c[j]=a[m+1+j];
    }
    i=0; 
    j=0; 
    k=l; 
    while(i<n1 && j<n2)
    {
        if(b[i]<=c[j])
        {
            a[k]=b[i];
            i++;
        }
        else
        {
            a[k]=c[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=b[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=c[j];
        j++;
        k++;
    }
}

void mergeSort(long long int a[],int l,int r)
{
    int m;
    if(l<r)
    {
        m=l+(r-l)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main()
{
    int i,n;
    scanf("%d",&n);
    long long int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    mergeSort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%lld",a[i]);
        if(i<n-1) printf(" ");
    }
    printf("\n");
    return 0;
}
