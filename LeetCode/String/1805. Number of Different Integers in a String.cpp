// 1805. Number of Different Integers in a String
class Solution {
public:
    int numDifferentIntegers(string word) {
        
        int n = word.size();
        set<string> st;
        string num = "";
        bool flag = false;

        for(int i=0;i<n;i++){
            if(word[i]>='a' and word[i]<='z'){
                if(num=="" and flag){
                    st.insert("0");
                }
                if(num.size()>0) st.insert(num);
                num = "";
                flag = false;
                continue;
            }
            else {
                if(num.size()==0 and word[i]=='0'){
                    flag = true;
                    continue;
                } 
                else num+=word[i];
            }
        }
        if(num=="" and flag){
            st.insert("0");
        }
        if(num.size()>0) {
            st.insert(num);
        }
        return st.size();
    }
};