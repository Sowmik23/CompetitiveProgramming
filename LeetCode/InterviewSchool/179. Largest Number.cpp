class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string> str;
        
        for(auto i: nums){
            str.push_back(to_string(i));
        }
      
        //sort(str.begin(), str.end(), compare);
        sort(str.begin(),str.end(), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        //sort(begin(str), end(str), [](string &s1, string &s2){ return s1+s2>s2+s1; });
       // for(auto i: str) cout<<i<<" ";
        
        
        string res = "";
        for(auto i: str) res+=i;
        
        if(res[0]=='0') return "0";
        return res;
    }
    
private:
    static bool compare(string a, string b){
        
        return a+b>b+a;
    }
};
