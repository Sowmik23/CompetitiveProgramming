#include <iostream>
using namespace std;

int main() {
	int t,n,d;
	scanf("%d",&t);
	while(t--){
	    if(t==-1) break;
	    scanf("%d%d",&n,&d);
	    int arr[n];
	    for(int i=0;i<n;i++){
	        scanf("%d",&arr[i]);
	    }
	    //printf("%d %d\n",n,d);
	    int cnt=0;
	    for(int i=d;i<(n+d);i++){
	        cnt++;
	        if(cnt<n) printf("%d ",arr[i%n]);
	        if(cnt==n) printf("%d\n",arr[i%n]);
	    }
	   }
	    
	return 0;
}
