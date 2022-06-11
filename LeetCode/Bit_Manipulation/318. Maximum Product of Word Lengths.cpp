class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        
        int res = 0;
        for(int i=0;i<words.size();i++){
            string x = words[i];
            bitset<26> xbit;
            for(int k=0;k<x.size();k++){
                xbit[x[k]-'a'] = 1;
            } 
                
            for(int j=i+1;j<words.size();j++){
                string y = words[j];
                
                bitset<26> ybit;
                for(int k=0;k<y.size();k++){
                    ybit[y[k]-'a'] = 1;
                }   
                
                int cnt = (xbit & ybit).count();
                if(cnt>=1) continue;
                else {
                    int m = x.size();
                    int n = y.size();
                    res = max(res, (m*n));
                }
            }
        }
        
        return res;
    }
};
