class Solution {
public:
    int minimumMoves(string s) {
        
        bool flag = false;
        int cnt = 0, res = 0;
        
        for(int i=0;i<s.size();){
            
            if(s[i]=='X'){
                res++;
                i+=3;
            }
            else i++;
            // cout<<i<<endl;
        }
        
        return res;
    }
};
