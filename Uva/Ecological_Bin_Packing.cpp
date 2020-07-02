#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int b1,b2,b3,g1,g2,g3,c1,c2,c3,res;
	
	while(scanf("%d%d%d%d%d%d%d%d%d",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3)==9)
	{
		//BCG/BGC/CBG/CGB/GBC/GCB   as alphabatically first//
		
		int a1 = (g1+c1) + (b2+g2) + (b3+c3);  //BCG
		int a2 = (g1+c1) + (b2+c2) + (b3+g3);  //BGC
		int a3 = (b1+g1) + (g2+c2) + (b3+c3);  //CBG
		int a4 = (g1+b1) + (b2+c2) + (g3+c3);  //CGB
		int a5 = (b1+c1) + (g2+c2) + (b3+g3);  //GBC
		int a6 = (b1+c1) + (b2+g2) + (g3+c3);  //GCB
		
		//cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<" "<<a6<<endl;
		
		res = min(a1,a2);
		res = min(res,a3);
		res = min(res,a4);
		res = min(res,a5);
		res = min(res,a6);
		
		if(res==a1)  cout<<"BCG "<<res<<endl;
		else if(res==a2) cout<<"BGC "<<res<<endl;
		else if(res==a3) cout<<"CBG "<<res<<endl;
		else if(res==a4) cout<<"CGB "<<res<<endl;
		else if(res==a5) cout<<"GBC "<<res<<endl;
		else if(res==a6) cout<<"GCB "<<res<<endl;
	}
	
	return 0;
}
