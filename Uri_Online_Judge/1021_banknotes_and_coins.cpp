#include <stdio.h>

int main()
{
	int x,y,z,a,b,d_100,d_50,d_20,d_10,d_5,d_2,d_1;
	double N,coin;
	int n;

	scanf("%lf",&N);

	n = N;

	coin=N*100;

	int changed_coin = (int)coin%100;

	// printf("%d %lf\n",changed_coin, coin);


	d_100=n/100;

	x=n%100;

	d_50=x/50;

	y=x%50;

	d_20=y/20;

	z=y%20;

	d_10=z/10;

	a=z%10;

	d_5=a/5;

	b=a%5;

	d_2=b/2;

	d_1=b%2;

	printf("NOTAS:\n%d nota(s) de R$ 100.00\n%d nota(s) de R$ 50.00\n%d nota(s) de R$ 20.00\n%d nota(s) de R$ 10.00\n%d nota(s) de R$ 5.00\n%d nota(s) de R$ 2.00\n",d_100,d_50,d_20,d_10,d_5,d_2);

	int c_50,c_25,c_10,c_5,c_1;

	c_50=changed_coin/50;
	changed_coin = changed_coin%50;
	c_25=changed_coin/25;
	changed_coin=changed_coin%25;
	c_10=changed_coin/10;
	changed_coin=changed_coin%10;
	c_5=changed_coin/5;
	c_1=changed_coin%5;

	printf("MOEDAS:\n%d moeda(s) de R$ 1.00\n%d moeda(s) de R$ 0.50\n%d moeda(s) de R$ 0.25\n%d moeda(s) de R$ 0.10\n%d moeda(s) de R$ 0.05\n%d moeda(s) de R$ 0.01\n",d_1,c_50,c_25,c_10,c_5,c_1);

return 0;
}
