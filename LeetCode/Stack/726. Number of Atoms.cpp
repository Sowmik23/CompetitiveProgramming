// 726. Number of Atoms
class Solution {
public:
    string countOfAtoms(string formula) {
        
        int n = formula.size();
        stack<pair<string, int>> stk;

        string str = "";
        int cnt = 0;
        int mul = 1;

        for(int i=0;i<n;i++){
            char fmla = formula[i];

            if(fmla>='A' and fmla<='Z'){
                if(str=="") str=fmla;
                else {
                    stk.push({str, 1});
                    str = fmla;
                }
            }    
            else if(fmla>='a' and fmla<='z'){
                str+=fmla;
            } 
            else if(fmla>='0' and fmla<='9'){
                if(str.size()>0){
                    stk.push({str, 1});
                    str = "";
                }
                cnt = cnt*10+(fmla-'0');
                if((i+1<n and !(formula[i+1]>='0' and formula[i+1]<='9')) or i==n-1){
                    auto top = stk.top();
                    stk.pop();
                    // cout<<top.first<<" -- "<<cnt<<endl;
                    stk.push({top.first, cnt});
                    cnt = 0;
                }
            }
            else if(fmla=='('){
                if(str!=""){
                    stk.push({str, 1});
                    str = "";
                }
                //push into stack
                stk.push({"(", 0});
            }
            else if(fmla==')'){
                if(str!=""){
                    stk.push({str, 1});
                    str = "";
                }
                //while pull from stack
                mul = 0;
                i++;
                while(i<n and formula[i]>='0' and formula[i]<='9'){
                    mul = mul*10+(formula[i]-'0');
                    i++;
                }
                if(mul==0) mul = 1;
                i--;
                stack<pair<string, int>> tmp;
                while(!stk.empty() and stk.top().first!="("){
                    auto top = stk.top();
                    stk.pop();
                    string name = top.first;
                    int c = top.second;
                    // cout<<name<<" -> "<<c<<endl;
                    c*=mul;
                   
                    tmp.push({name, c});
                }
                stk.pop();
                while(!tmp.empty()){
                    auto t = tmp.top();
                    tmp.pop();
                    // cout<<t.first<<" <- "<<t.second<<endl;
                    stk.push(t);
                }
            }
        }
        if(str.size()>0) stk.push({str, 1});

        map<string, int> mp;
        while(!stk.empty()){
            auto t = stk.top();
            stk.pop();
            mp[t.first]+=t.second;
        }

        str = "";
        for(auto& m: mp){
            // cout<<m.first<<" "<<m.second<<endl;
            str+=m.first;
            if(m.second>1) str+=to_string(m.second);
        }
        return str;
    }
};