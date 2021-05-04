#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string replaceDigits(string s) {
        
        string str="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' and s[i]<='9'){
                int x = s[i];
                
                int p = s[i-1];
                //cout<<p<<" P x "<<x<<endl;;
                int y = (p + x) - 48;
                
                str+=(char)y;
            }
            else str+=s[i];
        }
        return str;
    }
};

int main(){
	
	Solution s;
	string ss = s.replaceDigits("a1c1e1");
	
	cout<<ss<<endl;
	
	return 0;
}
