class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle=="") return 0;
        
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[0]){
                int j=i+1, k = 1;
                bool flag = true;
                while(j<haystack.size() and k<needle.size()){
                    if(haystack[j]!=needle[k]){
                        
                        flag = false;
                        break;
                    }
                    j++;
                    k++;
                }
                if(flag==true and k==needle.size()) return i;
            }
        }
        return -1;
    }
};
