class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> mp;

        for(int i=0;i<n;i++){
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            mp[a].push_back({b, val});
            mp[b].push_back({a, 1.0/val});
        }

        vector<double> res;
        for(int i=0;i<queries.size();i++){
            
            string numerator = queries[i][0];
            string denomerator = queries[i][1];

            if(mp.find(numerator)==mp.end()) res.push_back(-1.0);
            else {
                double val = bfs(numerator, denomerator, mp);
                res.push_back(val);
            }
        }
        return res;
    }
private:
    double bfs(string numerator, string denomerator, unordered_map<string, vector<pair<string, double>>> &mp){

        unordered_set<string> visited;
        queue<pair<string, double>> q;
        q.push({numerator, 1.0});
        visited.insert(numerator);

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            string _next = top.first;
            double ans = top.second;
            if(_next==denomerator) return ans;

            for(auto& neighbor: mp[_next]){
                string u = neighbor.first;
                double val = neighbor.second;
                if(visited.find(u)==visited.end()){
                    visited.insert(u);
                    q.push({u, (double)ans*val});
                }
            }
        }
        return -1.0;
    }
};






class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        
        unordered_map<string, unordered_map<string, double>> mp;
        
        mp = buildGraph(equations, values);
        
        vector<double> res(queries.size());
        
        
        for(int i=0;i<queries.size();i++){
            unordered_set<string> visited;
            
            res[i] = dfs(queries[i][0], queries[i][1], visited, mp);
        }
        
        
        return res;
    }
private:
    double dfs(string c, string d, unordered_set<string> &visited, unordered_map<string, unordered_map<string, double>> &mp){
        
        //rejection case
       if(mp.find(c)==mp.end()) return -1.0;
        
        //acceptance case
       if(mp[c].find(d)!=mp[c].end()) return mp[c][d];
        
        visited.insert(c);
        
        for(auto& i: mp[c]){
            if(!visited.count(i.first)){
                double ans = dfs(i.first, d, visited, mp);
                if(ans!=-1.0) return (double) ans*(i.second);
            }
        }
        
        return -1.0;
    }
    
    
    unordered_map<string, unordered_map<string, double>> buildGraph(vector<vector<string>> &equations, vector<double> &values){
        
        unordered_map<string, unordered_map<string, double>> mp;
        
        for(int i=0;i<equations.size();i++){
            string u = equations[i][0];
            string v = equations[i][1];    
            double val = values[i];
            
            mp[u].insert({v, val});
            mp[v].insert({u, (double)1/val});
        }
        
        return mp;
    }
};
