#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        
        int x = calculateValue(firstWord);
        int y = calculateValue(secondWord);
        int z = calculateValue(targetWord);
        cout<<x<<" "<<y<<" "<<z<<endl;
        
        if(x+y==z) return true;
        else return false;
    }
    
private:
    int calculateValue(string str){
        
        string s="";
        for(int i=0;i<str.size();i++){

            s+= to_string(str[i] - 'a');
            //cout<<str[i]-'a'<<" fdf ";
           // cout<<s<<endl;
        }
    
      //  cout<<s<<endl;
        int val = atoi(s.c_str());
        
       // cout<<val<<endl;
        return val;
    }
    
};


int main(){
	
	Solution s ;
	
	string a = "acb";
	string b = "cba";
	string c = "cdb";
	
	bool k = s.isSumEqual(a, b, c);
	
	if(k==true) cout<<"Yes"<<endl;
	else cout<<"NO"<<endl;
	
	return 0;
}
