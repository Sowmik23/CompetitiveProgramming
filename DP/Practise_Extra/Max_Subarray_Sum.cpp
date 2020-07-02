/*A[]={3, -4, 9, -8, 8, 7}
 *maximum contiguous subarry= {9, -8, 8, 7}
 *maximum contiguous subarray sum= 16
 * */

#include <bits/stdc++.h>
using namespace std;


//Brute force solution
int maxSubarraySum(int arr[],int n)
{
		int overall_sum = 0;
		int curr_sum;
		
		for(int i=0;i<n;i++)
		{
			curr_sum = 0;
			for(int j=i;j<n;j++)
			{
				curr_sum +=arr[j];
				if(curr_sum>overall_sum)
				{
					overall_sum = curr_sum;
				}
			}
		}
		
		return overall_sum;
}

//dp solution
int kadane(int arr[], int n)
{
	int overall_sum =0;
	int curr_sum = 0;
	
	for(int i=0;i<n;i++)
	{
		curr_sum = max(arr[i],curr_sum + arr[i]);
		
		overall_sum = max(overall_sum , curr_sum);
	}
	return overall_sum;
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	
	printf("The maximum subarray sum is: %d\n",kadane(arr,n));//maxSubarraySum(arr,n));
	
	return 0;
}
