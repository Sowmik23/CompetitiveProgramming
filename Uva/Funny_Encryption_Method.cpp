#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	char n[11];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",n);  //input decimal number
		
		//string decimal_to_binary = bitset<16>(n).to_string(); //16 ghor porjonto dekhabe binary number
		//cout<<decimal_to_binary<<endl;
		//printf("%x\n",n);  //Hexadecimal number
		//printf("%o\n",n); //octal number
		
		int x1,x2,b1=0,b2=0;
		sscanf(n,"%d",&x1); 
		sscanf(n,"%x",&x2);
		
		while(x1)
		{
			b1+=x1&1;
			x1/=2;
		} 
		while(x2)
		{
			b2+=x2&1;
			x2/=2;
		} 
		printf("%d %d\n",b1,b2);
	}
	
	return 0;
}
