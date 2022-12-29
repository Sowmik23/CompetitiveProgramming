class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {

        map<string, int> visited;
        queue<pair<string, int>> q;
        q.push({start, 0});

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            //cout<<top.first<<" "<<top.second<<endl;
            if(top.first==end) return top.second;
            if(visited.find(top.first)!=visited.end()) continue;
            visited[top.first] = 1;

            for(auto& str: bank){
                if(canBeMutated(top.first, str)) q.push({str, top.second+1});
            }
        }
        return -1;
    }
private:
    bool canBeMutated(string from, string to){
        int cnt = 0;
        for(int i=0;i<from.size();i++){
            if(from[i]!=to[i]) cnt++;
            if(cnt>1) return false;
        }
        return cnt==1;
    }
};
