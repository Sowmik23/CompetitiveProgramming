#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	scanf("%d",&n);
	char x[201],y[201];
	
	for(int i=0;i<n;i++)
	{
		scanf("%s %s",x,y);
		//cout<<x<<" " <<y<<endl;
		
		int l1,l2;
		l1 = strlen(x);
		l2 = strlen(y);
		//printf("%d %d\n",l1,l2);
		int k ;
		if(l1>=l2) k = l2;
		else k = l1;
		
		int l=0,d,ans;
		int carry = 0;
		int flag = 0;
		
		for(int j=0;j<k;j++)
		{
			int dd = x[l]-'0';
			int ee = y[j]-'0';
			//printf("%d %d\n",dd,ee);
			
			d = dd + ee + carry;
			l++;
			if(d>=10)
			{
				ans = d%10;
				carry = 1;
			}
			else 
			{
				carry = 0;
				ans = d;
			}
			if(ans!=0) flag = 1;
			
			if(flag ==1) printf("%d",ans);
			
		}
		if(l1>=l2)
		{
			for(int ii=l;ii<l1;ii++)
			{
				d =  x[ii]-'0' + carry;
				//l++
				//printf("%d\n",d);
				
				if(d>=10)
				{
					ans = d%10;
					carry = 1;
				}
				else {
					carry = 0;
					ans = d;
				}
				if(ans!=0) flag = 1;
			
				if(flag ==1) printf("%d",ans);
				
			}
			if(carry==1) printf("1");
		}
		else 
		{
			for(int ii=l;ii<l2;ii++)
			{
				d =  y[ii]-'0' + carry;
				//l++
				//printf("%d\n",d);
				
				if(d>=10)
				{
					ans = d%10;
					carry = 1;
				}
				else {
					carry = 0;
					ans = d;
				}
				if(ans!=0) flag = 1;
			
				if(flag ==1) printf("%d",ans);
			}
			if(carry==1) printf("1");
		}
		
		printf("\n");
	}
	
	return 0;
}
