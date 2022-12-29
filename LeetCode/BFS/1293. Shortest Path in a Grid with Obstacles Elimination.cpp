class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        // // recursion: TLE
        // vector<vector<int>> visited(m, vector<int> (n, 0));
        // int res = recursive(grid, visited, m, n, k, m-1, n-1);
        // if(res>m*n) return -1;
        // return res;

        // //recursion with memoizatoin: Accepted
        // vector<vector<int>> visited(m+1, vector<int> (n+1, 0));
        // vector<vector<vector<int>>> memo(m+1, vector<vector<int>> (n+1,  vector<int> (k+5, -1)));
        // int res = recursionWithMemo(grid, visited, memo, m, n, k, m-1, n-1);
        // if(res>=m*n) return -1;
        // return res;

        // //BFS
        vector<vector<int>> visited(m,  vector<int> (n, -1));
        queue<vector<int>> q;
        q.push({0, 0, 0, k});

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            int x = top[0];
            int y = top[1];

            if(x<0 or y<0 or x>=m or y>=n) continue;

            if(x==m-1 and y==n-1) return top[2];

            if(grid[x][y]==1){
                if(top[3]>0) top[3]--;
                else continue;
            }

            if(visited[x][y]!=-1 and visited[x][y]>=top[3]) continue;
            visited[x][y]  = top[3];

            q.push({x+1, y, top[2]+1, top[3]});
            q.push({x-1, y, top[2]+1, top[3]});
            q.push({x, y+1, top[2]+1, top[3]});
            q.push({x, y-1, top[2]+1, top[3]});
        }

        return -1;
    }
private:
    int recursive(vector<vector<int>> &grid, vector<vector<int>> &visited, int m, int n,int k, int i, int j){

        if(i==0 and j==0) return 0;
        if(i<0 or i>=m or j<0 or j>=n or visited[i][j]) return 99999;

        if(grid[i][j]==1) {
            if(k>0) k--;
            else return 99999;
        }
        visited[i][j] = 1;
        int right = 1+recursive(grid, visited, m, n, k, i+1, j);
        int left = 1+recursive(grid, visited, m, n, k, i-1, j);
        int up = 1+recursive(grid, visited, m, n, k, i, j+1);
        int down = 1+recursive(grid, visited, m, n, k, i, j-1);
        visited[i][j] = 0;
        return min({right, left, up, down});
    }

    int recursionWithMemo(vector<vector<int>> &grid, vector<vector<int>> &visited, vector<vector<vector<int>>> &memo, int m, int n,int k, int i, int j){

        if(i<0 or i>=m or j<0 or j>=n or visited[i][j]) return 99999;
        if(i==0 and j==0) return memo[i][j][k] = 0;
        if(memo[i][j][k]!=-1) return memo[i][j][k];

        if(grid[i][j]==1) {
            if(k>0) k--;
            else return memo[i][j][k] = 99999;
        }

        visited[i][j] = 1;

        int left = 1+recursionWithMemo(grid, visited, memo, m, n, k, i, j-1);
        int right = 1+recursionWithMemo(grid, visited, memo, m, n, k, i, j+1);
        int up = 1+recursionWithMemo(grid, visited, memo, m, n, k, i-1, j);
        int down = 1+recursionWithMemo(grid, visited, memo, m, n, k, i+1, j);

        visited[i][j] = 0;

        return memo[i][j][k] = min({left,right, up, down});
    }
};
 
