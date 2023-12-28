class Solution {
public:
    vector<int> parent;

    int removeStones(vector<vector<int>>& stones) {

        unordered_map<int, vector<int>> rowMap, colMap;

        for(int i=0;i<stones.size();i++){
            rowMap[stones[i][0]].push_back(i);
            colMap[stones[i][1]].push_back(i);
        }

        for(int i=0;i<stones.size();i++) parent.push_back(i);

        for(int i=0;i<stones.size();i++){
            for(int j: rowMap[stones[i][0]]) Union(i, j);
            for(int j: colMap[stones[i][1]]) Union(i, j);
        }

        unordered_set<int> unique;
        for(auto& n: parent) unique.insert(find(n));

        return stones.size()-unique.size();
    }
private:
    void Union(int x, int y){
        parent[find(x)] = find(y);
    }
    int find(int x){
        if(parent[x]!=x) return parent[x] = find(parent[x]);
        return x;
    }
};
