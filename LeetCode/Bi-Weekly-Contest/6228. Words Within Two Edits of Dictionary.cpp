class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {

        vector<string> res;
        for(int i=0;i<queries.size();i++){
            string str = queries[i];

            if(findMatch(str, dictionary)){
                res.push_back(str);
            }
        }
        return res;
    }
private:
    bool findMatch(string str, vector<string>& dictionary){

        for(auto& d: dictionary){
            int cnt = 0;
            for(int j=0;j<d.size();j++){
                if(d[j]!=str[j]) cnt++;
                if(cnt>2) break;
            }
            if(cnt<=2) return true;
        }
        return false;
    }
};
