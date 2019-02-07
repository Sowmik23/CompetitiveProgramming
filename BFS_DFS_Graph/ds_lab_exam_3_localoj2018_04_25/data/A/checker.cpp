#include<bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
ui64 judgeHash[] = {14523822313702229147ULL,14721708184152594698ULL,16969927779643626745ULL,4589544101861199180ULL,13731014919181156925ULL,17499184744717692551ULL,2497598767198202085ULL,5020156747840727075ULL,16798474031225095456ULL,7161529339773223380ULL};
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
	check(10);
	return 0;
}
