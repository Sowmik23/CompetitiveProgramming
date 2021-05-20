class Solution {
public:
    int maxVowels(string s, int k) {
        
        int left=0, right = 0, mx = INT_MIN, cnt=0;
        
        while(right<s.size()){
            char c1 = s[right];
           
            if(isVowel(c1)) cnt++;
            
            if(right-left+1<k) right++;
            else if(right-left+1==k) {
                mx = max(mx, cnt);
                char c2 = s[left];
                if(isVowel(c2)) cnt--;
                
                left++;
                right++;
            }
        }
        return mx;
    }
    
    private:
    bool isVowel(char c1){
        if(c1=='a' or c1=='e' or c1=='i' or c1=='o' or c1=='u') return true;
        return false;
    }
};
