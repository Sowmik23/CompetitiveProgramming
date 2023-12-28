// 1921. Eliminate Maximum Number of Monsters


class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        /*
        int n = dist.size();
        vector<pair<int, int>> merged;

        for(int i=0;i<n;i++){
            merged.push_back({dist[i], speed[i]});
        }

        sort(merged.begin(), merged.end(), [](auto &a, auto& b){
            return (a.first-a.second)<(b.first-b.second);
        });

        for(auto &x: merged){
            cout<<x.first<<" "<<x.second<<endl;
        }

        int cnt = 0;
        int minute = 0;
        for(auto &m : merged){
            int x = m.first - m.second*minute;
            if(x<0) return cnt==0 ? 1 : cnt;
            else {
                cnt++;
                minute++;
            }
        }

        return n;
        */

        //sort by arrival time
        int n = dist.size();
        vector<float> arrivalTime;
        for(int i=0;i<n;i++){
            arrivalTime.push_back((float)dist[i]/speed[i]);
        }

        sort(arrivalTime.begin(), arrivalTime.end());

        int cnt = 0;
        for(int i=0;i<n;i++){
            if(arrivalTime[i]<=i) break;
            cnt++;
        }
        return cnt;
    }
};