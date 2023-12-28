class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {

        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;

        for(auto& s: paths){
            int cnt = 0;
            stringstream ss(s);
            string str;
            string path="";
            while(ss>>str){
                //cout<<str<<endl;
                if(cnt==0){
                    path=str;
                    cnt++;
                    continue;
                }
                string name="";
                string file="";
                int i=0;
                while(i<str.size() and str[i]!='('){
                    name+=str[i];
                    i++;
                }
                i++;
                while(i<str.size() and str[i]!=')'){
                    file+=str[i];
                    i++;
                }
                //cout<<name<<" "<<file<<endl;
                mp[file].push_back(path+"/"+name);
            }
        }
        for(auto& m: mp){
            if(m.second.size()>1) res.push_back(m.second);
            //cout<<m.first<<" :";
            //for(auto& x: m.second) cout<<x<<" ";
            //cout<<endl;
        }

        return res;
    }
};
