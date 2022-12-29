class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {


        vector<int> points(student_id.size(), 0);
        unordered_map<string, int> posMap;
        unordered_map<string, int> negMap;

        for(auto& s: positive_feedback){
            posMap[s] = 1;
        }
        for(auto& s: negative_feedback){
            negMap[s] = 1;
        }

        for(int i=0;i<report.size();i++){
            string rpt = report[i];
            stringstream ss(rpt);
            string word;

            while(ss>>word){
                if(posMap.find(word)!=posMap.end()) {
                    points[i]+=3;
                }
                else if(negMap.find(word)!=negMap.end()) {
                    points[i]-=1;
                }
            }
        }

        vector<pair<int, int>> tmp;
        for(int i=0;i<points.size();i++){
            tmp.push_back({points[i], student_id[i]});
        }
        sort(tmp.begin(), tmp.end(), [](auto& a, auto& b){
            if(a.first==b.first) return a.second<b.second;
            return a.first>b.first;
        });

        vector<int> res;
        int cnt = 0;
        for(auto& i: tmp) {
            res.push_back(i.second);
            cnt++;
            if(cnt==k) break;
        }

        return res;
    }
};
