class Solution {
public:
    int lengthOfLastWord(string s) {
        
        if(s.size()==0) return 0;
        string str = "";
        for(int i=s.size()-1;i>=0;i--){
            if((s[i]==' ' and str.size()>0) or i<0) break;
            else if(s[i]!=' ') str+=s[i];
        }
        
        // for(int i=0;i<str.size()/2;i++){
        //     swap(str[i], str[str.size()-i-1]);
        // }
        //cout<<str<<endl;
        return str.size();
    }
};
