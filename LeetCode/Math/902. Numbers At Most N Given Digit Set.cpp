class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        
        
        //mathmatical but hard problem
        //needs a lot of mathematical concepts
        
        //Dynamic Programming / Mathematics
        
        //Time: log(N)
        //Space: log(N)
        
        string target = to_string(n);
        int targetLen = target.size();
        int size = digits.size();
        
        int cnt = 0;
        
        for(int i=1;i<targetLen;i++){
            cnt+=pow(size, i);
        }
        
        for(int i=0;i<targetLen;i++){
            bool hasSameDigit = false;
            
            for(string& digit: digits){
                if(digit[0]<target[i]){
                    cnt+=pow(size, targetLen-i-1);
                }
                else if(digit[0]==target[i]){
                    hasSameDigit = true;
                }
            }
            
            if(!hasSameDigit) return cnt;
        }
        
        return cnt+1;
    }
};
