#include <bits/stdc++.h>
using namespace std;

int main()
{
	double h,m,ans,h_angle,m_angle;
	while(scanf("%lf:%lf",&h,&m))
	{
		if(h==0 && m==0) break;
		
		h_angle=h*30 + (m/60)*30;
		m_angle =m*6;
		ans=abs(h_angle-m_angle);
		if(ans>180) ans=360-ans;
		printf("%.3lf\n",ans);
	}
	
	return 0;
}

