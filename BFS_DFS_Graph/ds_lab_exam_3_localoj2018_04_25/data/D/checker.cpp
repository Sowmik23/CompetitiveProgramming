#include<bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
ui64 judgeHash[] = {9004213629533478347ULL,1978500728352045708ULL,0ULL,16755150105143782718ULL,17165455383940159320ULL};
ui64 findHash(char filename[]){
    FILE *fp = fopen(filename,"r");
    ui64 p = 1000000007;
    char c;
    ui64 hash = 0, coeff = 1;
    while((c = fgetc(fp))!=EOF){
        hash += (c * coeff);
        coeff *= p;
    }
    fclose(fp);
    return hash;
}

void check(int cs){
    int i;
    ui64 scHash;
    for(i = 1; i <= cs; i++){
        char file[100],infile[100];
        sprintf(file,"%d.out",i);
        sprintf(infile,"%d.in",i);
        printf("Case %d: ",i);
		FILE *fp;
		int flag = 0;
        if((fp = fopen(infile, "r")) == NULL) flag = 1;
        else scHash = findHash(file);
        if(!flag && scHash == judgeHash[i-1])printf("Passed\n");
        else printf("Failed\n");
    }
}
int main(){
	check(5);
	return 0;
}
