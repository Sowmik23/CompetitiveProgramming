#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	long long int arr[n];
	for (int i=0;i<n;i++){
		scanf("%lld", &arr[i]);
	}
	

	int ans=n-1, b=0, x;
	std::map<int, int> freq;
	for (int j = 0; j < n; ++j)
	{	
		bool flag = true;
		for (int i = 0; i < j; ++i)
		{
			freq[arr[i]]++;
			if (freq[arr[i]]==2)
			{
				flag = false;
				break;
			}
		}

		b = n;
		for (int i = n-1; i >= j; --i)
		{
			freq[arr[i]]++;
			if (freq[arr[i]]==1)
			{
				b = i;
			}
			else break;
		}
		if (flag)
		{
			ans = min(ans, b-j);
		}
		freq.clear();
	}

	printf("%d\n",ans);


	return 0;
}