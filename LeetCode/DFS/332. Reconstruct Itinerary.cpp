// 332. Reconstruct Itinerary

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        // Eulerian path. Greedy DFS,

        //set: ordered+uniqueue, multiset: ordered+duplicate, 
        // unordered_set: uniqueue+unordered, unordered_multiset: unordered+duplicate
        // Know these and remember

        int n = tickets.size();
        map<string, multiset<string>> graph;
        vector<string> res;

        for(int i=0;i<n;i++){
            graph[tickets[i][0]].insert(tickets[i][1]);
        }

        dfs_visit(graph, res, "JFK");
        reverse(res.begin(), res.end());
        return res;
    }
private:
    void dfs_visit(map<string, multiset<string>> &graph, vector<string> &res, string start){
        
        while(graph[start].size()>0){
            string next = *graph[start].begin();
            graph[start].erase(graph[start].begin()); //you need to delete by reference not by value
            dfs_visit(graph, res, next);
        }
        res.push_back(start);
    }
};