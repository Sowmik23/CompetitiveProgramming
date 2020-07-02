#include <bits/stdc++.h>


using namespace std;

bool check(char ch){
	if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
	else return false;
}

int main(){
	
	int l1,l2;
	char s[1005],t[1005];
	
	scanf("%s",s);
	scanf("%s",t);
	
	l1 = strlen(s);
	l2 = strlen(t);
	
	if(l1==l2){
		for(int i=0;i<l1;i++){
			//cout<<check(s[i]);
			//cout<<check(s[i]);
			
			if(check(s[i])!=check(t[i])){
				printf("No\n");
				return 0;
			}
		}
		printf("Yes\n");
	}
	else printf("No\n");
	
	
	return 0;
}
