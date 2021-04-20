#include <stdio.h>


///Very very very Interesting problem :)
//Accepted

int main(){
	
	
	int shelf, query;
	
	scanf("%d%d", &shelf, &query);
	int books[1101]={0};
	int pages[1109][1109];
	
	int type, x, y;
	while(query--){
		scanf("%d", &type);
		if(type==1) {
			scanf("%d%d", &x, &y);   //x = shelf, y = pages
			books[x]++;
			pages[x][books[x-1]]=y;
		}
		else if(type==2) {
			scanf("%d%d", &x, &y);
			printf("%d\n", pages[x][y]);
		}
		else if(type==3) {
			scanf("%d", &x);
			printf("%d\n", books[x]);
		}
		
	}
	
	
	return 0;
}
