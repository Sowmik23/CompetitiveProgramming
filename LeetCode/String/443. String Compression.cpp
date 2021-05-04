
class Solution {
public:
    int compress(vector<char>& chars) {
        
 
        string str = "";
        int i=0, cnt=1;
        for(i=1;i<chars.size();i++){
            
            if(chars[i]!=chars[i-1]){
                str+=chars[i-1];
                if(cnt>1) str+=to_string(cnt);
                cnt = 1;
            }
            else cnt++;
        }
        str+=chars[i-1];
        if(cnt>1) str+=to_string(cnt);
        
        for(int i=0;i<str.size();i++){
            chars[i] = str[i];
           // cout<<chars[i]<<endl;
        }
        
        int res = str.size();
        
        return res;
    }
};
