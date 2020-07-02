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
	    
	    for(int i=n-1;i>=0;i--){
	        if(i) printf("%d ",arr[i]);
			else printf("%d\n",arr[i]);
	    }
	   
   }
	    
	return 0;
}
