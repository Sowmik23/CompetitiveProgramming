class Solution {
public:
    int myAtoi(string s) {
        
        int flag = 2; //means neutral
        long res = 0;
        bool not_num = false;
        bool num =false;
        
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') continue;
            else if(s[i]=='-' and flag==2){
                if(i<s.size()-1 and s[i+1]==' ') return 0;
                if(num==true) break;
                if(i>0 and s[i-1]>='0' and s[i-1]<='9') return 0;
                flag=0; //means false
            }
            else if(s[i]=='+' and flag==2){
                if(i<s.size()-1 and s[i+1]==' ') return 0;
                if(num==true) break;
                if(i>0 and s[i-1]>='0' and s[i-1]<='9') return 0;
                flag = 1; //means true 
            } 
            else if(s[i]>='0' and s[i]<='9'){
                num = true;
                if(not_num==true) break;
                
                if(i<s.size()-1 and s[i+1]==' ') {
                    not_num = true;  
                } 
                
                res = res*10 + s[i]-'0'; 
                if(res>INT_MAX){
                    if(flag==0){
                        return INT_MIN;
                    }
                    else {
                        return INT_MAX;
                    }
                }
            }
            else break;
        }
        
        if(flag==0){
            return -1*res;
        }
        else return res;
    }
};
