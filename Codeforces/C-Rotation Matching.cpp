#include <bits/stdc++.h>

using namespace std;

int arr[200005],brr[200005], position[200005], freq[200005];

int rotateOne(int n){
	int cnt=0;
	int x = arr[0];
	for(int i=0;i<n-1;i++){
		arr[i] = arr[i+1];
		if(arr[i]==brr[i]) cnt++;
	}
	arr[n-1] = x;
	if(arr[n-1]==brr[n-1]) cnt++;
	return cnt;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		position[arr[i]] = i;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&brr[i]);
		
		freq[i] = position[brr[i]] - i;
	}
	
	int mx = 0;
	
	for(int i=0;i<n;i++){
		//printf("%d ", freq[i]);
		if(freq[i]<0) freq[i] = freq[i] + n;
	}
	
	//for(int i=0;i<n;i++) printf("%d ", freq[i]);
	//cout<<endl;
	
	sort(freq, freq+n);
	int cnt=1;
	
	for(int i=0;i<n-1;i++){
		//printf("%d ", freq[i]);
		if(freq[i]!=freq[i+1]){
			if(mx<cnt ) mx = cnt;
			cnt=1;
		}
		else {
			cnt++;
		}
	}
	if(mx<cnt ) mx = cnt;
	
	printf("%d\n",mx);
	
	return 0;
}
