class Solution {
public:
    bool hasAllCodes(string s, int k) {
     
        if(k>s.size()) return false;
        
        set<int> st;
        string str = "";
        
        for(int i=0;i<s.size();i++){
            if(i<k){
                str+=s[i];
            }
            else {
                st.insert(stoi(str.substr(i-k, k), 0, 2));
                //cout<<str.substr(i-k, k)<<endl;
                str+=s[i];
            }
        }
        st.insert(stoi(str.substr(s.size()-k, k), 0, 2));
       // cout<<str.substr(s.size()-k, k)<<endl;
        
        //cout<<st.size()<<" "<<(pow(2, k))<<"sz"<<endl;
        if(st.size()!=pow(2,k)) return false;
        int x = 0;
        for(auto& i: st){
           //cout<<i<< " ";
            if(i!=x) return false;
            x++;
        }
        
        return true;
    }
};
