#include <bits/stdc++.h>
using namespace std;


int main(){
	
	int arr[] = {1, 11, 111, 1111, 2, 22, 222, 2222, 3, 33, 333, 3333, 4, 44, 444, 4444, 5, 55, 555, 5555, 6, 66, 666, 6666, 7, 77, 777, 7777, 8, 88, 888, 8888, 9, 99, 999, 9999};
	int t, n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		
		int sum = 0;
		for(int i=0;i<36;i++){
			if((i)%4==0) sum+=1;
			else if(i%4==1) sum+=2;
			else if(i%4==2) sum+=3;
			else if(i%4==3) sum+=4;
			if(arr[i]==n) {
				printf("%d\n", sum);
				break;
			}
		}
	}
	
	return 0;
}
