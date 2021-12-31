class Solution {
public:
    int smallestRepunitDivByK(int k) {
        
        //one approache: time: O(n), space: O(n)
        /*int n = 1;
        int remainder = 1;
        int len = 1;
        
        set<int> st;
        
        while(remainder%k!=0){
            n = remainder*10+1;
            remainder = n%k;
            
            if(st.count(remainder)!=0) return -1;
            else st.insert(remainder);
            
            len++;
        }
        
        return len;
        */
        
        //another approach: time:O(k), space: O(1)
        
        int remainder = 1;
        
        for(int i=0;i<=k;i++){
            remainder = remainder%k;
            if(remainder==0) return i+1;
            
            remainder = remainder*10 + 1;
        }
        return -1;
    }
};
