#include <bits/stdc++.h>

using namespace std;

int main()
{
	char str[51],ins[51];
	scanf("%s",str);
	scanf("%s",ins);

	int str_len = strlen(str);
	int ins_len = strlen(ins);
	
	//int cnt=1;
	int i=0,j=0;
	
	while(1){
		if(j==ins_len) break;
		if(i==str_len) break;
		
		if(str[i]==ins[j]){
			i++;
			j++;
			//cnt++;
		}
		else  j++;
	}
	
	printf("%d\n",i+1);
	
	
	
	return 0;
}
