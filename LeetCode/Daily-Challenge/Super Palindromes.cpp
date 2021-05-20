class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        
        int limit = 1e5;
        
        long long x = stoll(left); //convert string to int
        long long y = stoll(right);
        
        int res=0, start = 1, ans=0;
        
        //first check for odd length like this 1234321
        while(start<limit){
            string tmp = to_string(start);
            
            for(int i=tmp.size()-2;i>=0;i--){
                tmp+=tmp[i];
            }
            
            long long num = stoll(tmp); //now check if num^2 is palindrome
            num*=num;
            if(num>y) break;
            
            if(num>=x and check(num)) ans++;
            
            start++;
        }
        
        //now check for even length like this 123321
        start = 1;
        while(start<limit){
            string tmp = to_string(start);
            
            for(int i=tmp.size()-1;i>=0;i--){
                tmp+=tmp[i];
            }
            
            long long num = stoll(tmp);
            num*=num;
            if(num>y) break;
            
            if(num>=x and check(num)) ans++;
            
            start++;
        }
        
        return ans;
    }
    
    private:
    bool check(long long num){
        long long saved_number = num;
        long long reverse_num = 0;
        
        while(num){
            reverse_num = reverse_num*10 + num%10;
            num/=10;
        }
        
        return reverse_num==saved_number;
    }
};
