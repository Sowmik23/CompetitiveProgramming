#include <stdio.h>

#define MAX_BOLTS 500
#define MAX_NUTS 500

/*~global~copy~of~the~input~data~*/
int nuts,bolts;
int fits[MAX_BOLTS][MAX_NUTS];
	
void read_input_data(void)
{
	int n,b;
	scanf("%d%d",&bolts,&nuts);
	for(b=0;b<bolts;b++)
	{
		for(n=0;n<nuts;n++)
		{
			scanf("%d",&fits[b][n]);
		}
	}
}

/* data used to match nuts with bolts */
int nut_used[MAX_NUTS];
int bestmatched;

void init_match(void)
{
	int n;
	bestmatched=0;
	for(n=0;n<nuts;n++) nut_used[n]=0;
}
/*
void match_bolt(int boltno, int matched)
{
	int n;
	if(boltno==bolts)
	{
		if(matched>bestmatched)
		{
			bestmatched=matched;
		}
		return;
	}
	match_bolt(boltno+1,matched);	

		
	for(n=0;n<nuts;n++) 
	{
		if(!nut_used[n] && fits[boltno][n])
		{
			nut_used[n]=1;
			match_bolt(boltno+1,matched+1);
			nut_used[n]=0;
		}
	}
}*/

void match_bolt(int b,int m)
{
	int n,p=0;
	int boltno=b,matched=m;
	for(int i=boltno;;i++)
	{
		if(boltno==bolts)
		{
			if(matched > bestmatched)
			{
				bestmatched=matched;
			}
			p=1;
			break;
		}
		if(p==1)
		{
			for(n=0;n<nuts;n++)
			{
				if(!nut_used[n] && fits[boltno][n])
				{
					nut_used[n]=1;
					
					nut_used[n]=0;
					i=boltno + 1;
					matched= matched+1;
					break;
				}
			}	
		}
		p=0;
	}
	
	
	
}

int main()
{
	int cases,caseno;
	scanf("%d",&cases);
	
	for(caseno=1;caseno<=cases;caseno++)
	{
		read_input_data();
		init_match();
		match_bolt(0,0);
		
		printf("Case %d: ",caseno);
		printf("a maximum of %d nuts and bolts ",bestmatched);
		printf("can be fitted together\n");
	}
	
	return~0;
}
