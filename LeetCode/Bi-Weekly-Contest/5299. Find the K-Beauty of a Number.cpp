class Solution {
public:
    int divisorSubstrings(int num, int k) {
     
        
        string str = to_string(num);
        if(str.size()==k) return 1;
        
        int cnt = 0;
        
        string s="";
        for(int i=0;i<k;i++) s+=str[i];
        int x = stoi(s);
        if(x!=0 and num%x==0) cnt++;
        //cout<<"x: "<<x<<endl;
        for(int i=k;i<str.size();i++){
            s.push_back(str[i]);
            
            s = s.substr(1);
            
           // cout<<"s: "<<s<<endl;
            x = stoi(s);
            if(x!=0 and num%x==0) cnt++;
        }
        
        return cnt;
    }
};
