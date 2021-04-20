#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
     /*   unordered_map<char, int> umap1, umap2;
        
        for(auto i: s){
            umap1[i]++;
        }
         for(auto i: t){
            umap2[i]++;
        }
        
         for(auto it: umap2){
            if(umap1[it.first]<it.second) return it.first;
        }
        
        return NULL;*/
        
        /*
        char ans = 0;
        for(auto i: s){
            ans^=i;
        }
        for(auto i: t){
            ans^=i;
        }
        return ans;
        */
        
        char ans = 0;
        for(char i: s){
            ans^=i;
        }
        for(char i: t){
            ans^=i;
        }
        return ans;
    }
};


int main(){
	
	Solution s;
	
	string s1 = "klflkdsjf", s2="klflkdsjff";
	
	char k = s.findTheDifference(s1,s2);
	cout<<k<<endl;
	
	return 0;
}
