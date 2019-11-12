#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,sereja=0,dima=0;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
/*	
	for(int i=0;i<n/2;i++) {
		if(i%2==0){
			if(arr[i]>arr[n-i-1])
			{
				sereja+=arr[i];
				if(arr[n-i-1]>arr[i+1]) dima+=arr[n-i-1];
				else dima+=arr[i+1];
			}
			else {
				sereja+=arr[n-i-1];
				if(arr[n-i-2]>arr[i+1]) dima+=arr[n-i-2];
				else dima+=arr[i+1];
			}
		}
		else {
			if(arr[i]>arr[n-i-1])
			{
				dima+=arr[i];
				if(arr[n-i-1]>arr[i+1]) sereja+=arr[n-i-1];
				else sereja+=arr[i+1];
			}
			else {
				dima+=arr[n-i-1];
				if(arr[n-i-2]>arr[i+1]) sereja+=arr[n-i-2];
				else sereja+=arr[i+1];
			}
		}
	}
*/
	
	int i=0;
	int j=n-1;
	int flag = 0;
	
	while(i<=j){
		if(flag==0){
			if(arr[i]>arr[j]){
				sereja+=arr[i];
				i++;
			}
			else {
				sereja+=arr[j];
				j--;
			}
			flag =1;
		}
		else if(flag==1) 
		{
			if(arr[i]>arr[j]){
				dima+=arr[i];
				i++;
			}
			else {
				dima+=arr[j];
				j--;
			}
			flag =0;
		}
		
	}

	printf("%d %d\n",sereja,dima);
	
	return 0;
}

