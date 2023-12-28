// 1461. Check If a String Contains All Binary Codes of Size K
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        //Approach: 01
        /*
        int n = s.size();
        string str = "";
        int limit = pow(2, k)-1;
        //cout<<"limit: "<<limit<<endl;
        set<int> st;

        for(int i=0;i<n;i++){
            str+=s[i];
            if(i>=k){
                str = str.substr(1);
                int num = stoi(str, nullptr, 2);
                //cout<<num<<" "<<str<<endl;
                st.insert(num);
                if(num<0 or num>limit) return false;
            }
            else if(i==k-1){
                int num = stoi(str, nullptr, 2);
                //cout<<num<<" "<<str<<endl;
                st.insert(num);
                if(num<0 or num>limit) return false;
            }
        }
        return st.size()==limit+1;
        */

        //Approach: 02
        int n = s.size();
        set<string> st;
        string str = "";
        int limit = pow(2, k); // 1<<k same

        for(int i=k;i<=n;i++){
            str = s.substr(i-k, k);
            if(st.find(str)==st.end()){
                st.insert(str);
                if(st.size()==limit) return true;
            }
        }
        return false;
    }
};