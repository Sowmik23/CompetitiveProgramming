#include <bits/stdc++.h>

using namespace std;

int main()
{
	int d1,d2,h1,h2,m1,m2,s1,s2;
	char name[10];
	
	scanf("%s",name);
	scanf("%d",&d1);
	
	scanf("%d : %d : %d",&h1,&m1,&s1);
	
	scanf("%s",name);
	scanf("%d",&d2);
	
	scanf("%d : %d : %d",&h2,&m2,&s2);
	
	
	//printf("%d : %d : %d\n",h1,m1,s1);
	//printf("%d : %d : %d",h2,m2,s2);

	
	
	int total_seconds1 = 1*24*3600 + h1*3600 + m1*60 + s1;
	int total_seconds2 = (d2-d1+1)*24*3600 + h2*3600 + m2*60 + s2;
	
	
	int difference = total_seconds2 - total_seconds1;
	
	int newDay,newHour,newMin, newSec;
	
	newDay = difference/(24*3600);
	difference = difference%(24*3600);
	
	newHour = difference/3600;
	difference = difference%3600;
	
	newMin = difference/60;
	difference = difference%60;
	
	newSec = difference;
	
	
	printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n",newDay,newHour,newMin,newSec);
	
	
	
	return 0;
}
