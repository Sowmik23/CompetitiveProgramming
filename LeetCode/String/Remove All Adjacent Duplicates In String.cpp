class Solution {
public:
    string removeDuplicates(string s) {
        
        int flag = false;
        while(s.size()>=1){
            flag = false;
            for(int i=0;i<s.size()-1;i++){
                if(s[i]==s[i+1]){
                    flag = true;
                    if(s.size()<=2) {
                        s = "";
                        break;
                    }
                    //cout<<s<<" b"<<endl;
                    s.erase(s.begin()+i);
                  //  cout<<s<<" a1"<<endl;
                    s.erase(s.begin()+i);
                   // cout<<s<<" a2"<<endl;
                }
            }
           // cout<<s<<endl;
            if(flag==false) break;
        }
        
        return s;
    }
};
