#include <iostream>
using namespace std;

int main() {
	int t,n,d;
	scanf("%d",&t);
	while(t--){
	    if(t==-1) break;
	    scanf("%d",&n);
	    int arr[n];
	    for(int i=0;i<n;i++){
	        scanf("%d",&arr[i]);
	    }
	    //printf("%d %d\n",n,d);
	    int brr[n], j =1;
	    brr[0] = arr[n-1];
	    
	    int mx = arr[n-1];
	    for(int i=n-2;i>=0;i--){
	        if(arr[i]>=mx) {
				mx = arr[i];
				brr[j] = arr[i];
				j++;
			}
	    }
	    for(int k=j-1;k>=0;k--){
			if(k) printf("%d ",brr[k]);
			else printf("%d\n",brr[k]);
	   }
   }
	    
	return 0;
}
