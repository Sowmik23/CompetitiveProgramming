#include <stdio.h>
#include <string.h>
int main()
{
	char a[15], b[15], c[15];

	scanf("%s %s %s",a,b,c);
	
	//printf("%s\n%s\n%s\n",a,b,c);
	
	int x = strcmp(a,"vertebrado");
	int y = strcmp(a,"invertebrado");
	
	//printf("%d\n",x);

	if( x==0 )
	{
		//printf("hsoche na");

		if(strcmp(b, "ave") ==0 )
		{
			if(strcmp(c, "carnivoro") == 0)
			{
				printf("aguia\n");
			}
			else if(strcmp(c, "onivoro") ==0)
			{
				printf("pomba\n");
			}
		}

		else if(strcmp(b,"mamifero") ==0)
		{
			if(strcmp(c, "onivoro")==0)
			{
				printf("homem\n");
			}
			else if(strcmp(c,"herbivoro") ==0)
			{
				printf("vaca\n");
			}
		}

	}

	else if(y==0)
	{
		//printf("hsoche");
		if(strcmp(b,"inseto")==0)
		{
			if(strcmp(c,"hematofago") == 0)
			{
				printf("pulga\n");
			}
			else if(strcmp(c,"herbivoro") == 0)
			{
				printf("lagarta\n");
			}
		}
		else if(strcmp(b,"anelideo") == 0)
		{
			//printf("hsoche2");
			if(strcmp(c,"hematofago") == 0)
			{
				printf("sanguessuga\n");
			}
			else if(strcmp(c,"onivoro") == 0)
			{
				printf("minhoca\n");
			}
		}
	}


return 0;
}
