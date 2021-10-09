class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        int b = 0;
        int a = 0;
        int n = 0;
        int l = 0;
        int o = 0;
        
        int res = 0;
        
        for(int i=0;i<text.size();i++){
            if(text[i]=='b') b++;
            else if(text[i]=='a') a++;
            else if(text[i]=='n') n++;
            else if(text[i]=='o') o++;
            else if(text[i]=='l') l++;
        }
       
        int k = min(b, a);
        k = min(k, n);
        int m = min(l/2, o/2);
        k = min(k, m);
        res = max(res, k);
        
        return res;
    }
};
