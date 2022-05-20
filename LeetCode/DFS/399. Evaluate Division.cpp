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
