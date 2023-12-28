class Solution {
public:
    bool isStrictlyPalindromic(int n) {

        for(int base=2;base<=n-2;base++){

            if(!convertTobase(n, base)) return false;
        }

        return true;
    }
private:
    int convertTobase(int n, int base){
        string str = "";
        while(n>0){
            str = to_string(n%base)+str;
            n = n/base;
        }
        //cout<<str<<endl;
        for(int i=0;i<str.size()/2;i++){
            if(str[i]!=str[str.size()-i-1]) return false;
        }

        return true;
    }
};
