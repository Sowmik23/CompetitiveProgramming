class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        //shortest path: BFS

        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> visited(m, vector<int> (n, false));
        vector<int> directions = {1, 0, -1, 0, 1};

        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int z = q.front().second;
            //cout<<x<<" "<<y<<"  "<<z<<endl;
            q.pop();

            maze[x][y] = '+';
            if(visited[x][y]) continue;
            visited[x][y] = true;


            for(int i=0;i<4;i++){
                int xx = x+directions[i];
                int yy = y+directions[i+1];

                if((xx>=0 and xx<=m-1 and yy>=0 and yy<=n-1) and maze[xx][yy]=='.'){
                    if((xx==0 or xx==m-1 or yy==0 or yy==n-1)) return z+1;

                    q.push({{xx, yy}, z+1});
                }
            }
        }
        return -1;
    }
};
