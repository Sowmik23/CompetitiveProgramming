#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h1,h2,m1,m2,mm;
	
	scanf("%d:%d",&h1,&m1);
	scanf("%d:%d",&h2,&m2);
	
	int d ;
	//printf("d = %d\n",d);
	
	if(h1!=h2)
	{
		if(h1>h2)
		{
			d = 23 - h1;
			d+=h2;
		}
		else d = h2-h1;
		
		int m = 60 - m1;
	
		m+=m2;
	
		//printf("m = %d\n",m);
	
		int k = d*60;
	
		mm = m + k;
		//printf("%d\n",mm);
		
		mm-=60;
	}
	else 
	{
		mm = m2 - m1;
		//printf("%d\n",mm);
	}
	
	//printf("%d:%d\n",h1,m1);
	//printf("%d:%d\n",h2,m2);
	
	//printf("%d\n",mm);
	
	mm = mm/2;
	//printf("%d\n",mm);
	
	int hour = mm/60;
	int min = mm%60;
	
	//printf("%d:%d\n",hour,min);
	
	int aa = h1+hour;
	int bb = m1 + min;
	
	string s1 = to_string(aa);
	string s2 = to_string(bb);
	
	string ans1,ans2;
	
	if(s1.size()<2)
	{
		ans1 = "0";
		ans1+=s1;
		ans1+='\0';
	}
	else ans1 = s1;
	
	if(s2.size()<2)
	{
		ans2 = "0";
		ans2+=s2;
		ans2+='\0';
	}
	else ans2 = s2;
	
	string str = ans1+":"+ans2;
	
	//cout<<ans1<<":"<<ans2<<endl;
	//cout<<str<<endl;
	printf("%02d:%02d\n",h1+hour,m1+min);
	
	//printf("%s:%s\n",ans1,ans2);
	
	return 0;
}
