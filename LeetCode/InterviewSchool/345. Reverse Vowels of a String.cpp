class Solution {
public:
    string reverseVowels(string s) {
        
        int left = 0;
        int right = s.size()-1;
        
        while(left<right){
            if(check(s[left])==true and check(s[right])==true){
                swap(s[left], s[right]);
                left++;
                right--;
            }
            if(check(s[left])==false) left++;
            if(check(s[right])==false) right--;
        }
        
        return s;
    }
    
private:
    bool check(char ch){
        if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u' or ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U'){
            return true;
        }
        return false;
    }
};
