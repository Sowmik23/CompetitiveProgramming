#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string toLowerCase(string str) {
        int len = str.size();
        for(int i=0;i<len;i++){
            if(str[i]>='A' and str[i]<='Z'){
                str[i] = str[i]-'A'+ 'a';
            }
        }
        return str;
    }
};


int main(){
	Solution mysolution;
	
	
	cout<<mysolution.toLowerCase("BanGlaDesh")<<endl;
	
	
	
	return 0;
}
