// 1743. Restore the Array From Adjacent Pairs
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        int n = adjacentPairs.size();
        res = vector<int> (n+1);
        unordered_map<int, vector<int>> mp;

        for(auto& adjacentPair: adjacentPairs){
            mp[adjacentPair[0]].push_back(adjacentPair[1]);
            mp[adjacentPair[1]].push_back(adjacentPair[0]);
        }

        int start;
        for(auto& m: mp){
            if(m.second.size()==1) {
                start = m.first;
                break;
            }
        }

        dfs(0, start, INT_MIN, mp);
        
        return res;
    }
private:
    vector<int> res;
    void dfs(int idx, int start, int prev, unordered_map<int, vector<int>> &mp){

        res[idx] = start;
        for(auto& next: mp[start]){
            if(next!=prev){
                dfs(idx+1, next, start, mp);
            }
        }
    }
};