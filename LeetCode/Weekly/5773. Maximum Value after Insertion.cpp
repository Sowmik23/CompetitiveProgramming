class Solution {
public:
    string maxValue(string n, int x) {
        
        string res="";
        
        if(n[0]=='-'){
            //res+="-";
            int f=false;
            for(int i=0;i<n.size();i++){
                //cout<<n[i]<<" kkkk "<<endl;
                int y = n[i]-'0';
                if(x<y){
                    f = true;
                    //cout<<i<<endl;
                    
                    res+=(string)n.substr(0, i);
                    res+=to_string(x);
                    
                    //cout<<(string)(n.substr(0, i))<<" sowmik"<<endl;
                   // res+=(string)(n.substr(0, i+1));
                    
                    //cout<<x<<endl;
                   res+=(string)n.substr(i, n.size()-i+1);
                   //res+=(string)n.substr(i+1, n.size()-i+1);
                    break;
                }
            }
            if(f==false){
                res+=n;
                res+=to_string(x);
            }
        }
        else {
            res="";
            int flag=false;
            for(int i=0;i<n.size();i++){
                int y = n[i]-'0';
                //cout<<y<<endl;
                if(x>y){
                    flag=true;
                    //cout<<"eidkfjd"<<endl;
                    res+=(string)n.substr(0, i);
                    res+=to_string(x);
                    res+=(string)n.substr(i, n.size()-i+1);
                    break;
                }
            }
            if(flag!=true){
                res+=n;
                res+=to_string(x);
            }
        }
       // cout<<res<<endl;
        return res;
    }
};
