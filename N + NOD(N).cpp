#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define LL long long
#define L long
using namespace std;
L prime[1234567], mark[12345678],m;
void pr () {
    m=0;
    for (int i=4; i<12345678;i+=2)
        mark[i]=1;
    int N=sqrt(12345678)+1;
    for (int i=3;i<N;i+=2) {
        if (!mark[i]) {
            for (int j=i*i;j<12345678;j=j+i*2) {
                mark[j]=1;
            }
        }
    }
    for (int i=2;i<12345678;i++) {
        if(!mark[i])
            prime[m++]=i;
    }
}
bool checkprime( L a ) {
    L left = 0, right = m-1, mid;
    while ( left<=right ) {
        mid = (left+right)/2;
        if(prime[mid]==a)
            return true;
        else if (prime[mid]>a)
            right = mid-1;
        else
            left = mid + 1;
    }
    return false;
}
bool chcekcoprime(L a){
    L x = sqrt(a);
    if(checkprime(x) && x*x==a)
        return true;
    else return false;
}
L num[1234567],di[1234567];
void divisors () {
    L c=2,d,e,f,g;
    di[1]=1;
    for (L i=2;i<1234567;i++){
        d = sqrt(i)+1;
        c=1;
        e=i;
        f=1;
        if(checkprime(i))
            c=2;
        else if (chcekcoprime(i))
            c=3;
        else{
            for (L j=0;prime[j]*prime[j]<=e;j++){
                 f=0;
                while(e%prime[j]==0){
                   f++;
                    e=e/prime[j];
                }
                c*=(f+1);
            }
            if (e>1) c*=2;
        }
        di[i]=c;
    }
    return ;
}
void nu () {
    num[1]=1;
    for (m=2;m<1234567;m++) {
        num[m]=num[m-1]+di[num[m-1]];
        if(num[m]>1234567)
            break;
    }
    return;
}
L lower (L a) {
    L left = 1, right = m, mid;
    while (left<=right) {
        mid = (left+right)/2;
        if(num[mid]==a){
            //cout << mid << endl;
            right=mid-1;
        }
        else if ( num[mid]>a)
            right = mid-1;
        else
            left = mid + 1;
    }
    return right;
}
L upper (L b) {
      L left = 1, right = m, mid;
    while (left<=right) {
        mid = (left+right)/2;
      //  cout << mid << endl;
        if(num[mid]==b){
            left=mid+1;
        }
        else if ( num[mid]>b)
            right = mid-1;
        else
            left = mid + 1;
    }
    return left;
}
int main() {
 //   freopen( "in.txt","r",stdin );
    pr ();
    divisors();
    nu();
    int n;
    L A,B;
    scanf ("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf ("%ld %ld",&A,&B);
        L lo=lower(A), up = upper (B);
        printf ("Case %d: %ld\n",i,up-lo-1);
    }
    return 0;
}
