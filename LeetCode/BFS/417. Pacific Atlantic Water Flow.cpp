class Solution {
public:
    int m;
    int n;
    vector<vector<int>> res;
    vector<vector<bool>> pacific, atlantic;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        //bfs // dfs
        //Time: O(m*n)

        m = heights.size();
        n = heights[0].size();

        atlantic = pacific = vector<vector<bool>> (m, vector< bool> (n, false));

        for(int i=0;i<m;i++){
            bfs(heights, pacific, i, 0);
            bfs(heights, atlantic, i, n-1);
        }

        for(int i=0;i<n;i++){
            bfs(heights, pacific, 0, i);
            bfs(heights, atlantic, m-1, i);
        }

        return res;
    }
private:
    int directions[5] = {1, 0, -1, 0, 1};
    void bfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int x, int y){

        queue<pair<int, int>> q;
        q.push({x, y});

        while(!q.empty()){
            tie(x, y) = q.front();
            q.pop();
            if(visited[x][y]) continue;
            visited[x][y] =  true;

            if(pacific[x][y] and atlantic[x][y]) res.push_back({x, y});

            if(x+1<m and heights[x+1][y]>=heights[x][y]) q.push({x+1, y});
            if(x-1>=0 and heights[x-1][y]>=heights[x][y]) q.push({x-1, y});
            if(y+1<n and heights[x][y+1]>=heights[x][y]) q.push({x, y+1});
            if(y-1>=0 and heights[x][y-1]>=heights[x][y]) q.push({x, y-1});
        }
    }
};
