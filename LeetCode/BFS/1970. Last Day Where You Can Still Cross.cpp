// 1970. Last Day Where You Can Still Cross
class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        // Binary Search + Breadth-First Search
        /*
        int left = 1;
        int right = row*col;

        while(left<right){
            int mid = right-(right-left)/2;
            if(canCross(row, col, cells, mid)){
                left = mid;
            }
            else right = mid-1;
        }
        return left;
        */

        //Union Find
        vector<vector<int>> grid(row+1, vector<int> (col+1, 1));
        parent = vector<int> (row*col+3, -1);

        int start = row*col+1, end = row*col+2; //dummy node
        for(int j=0;j<col;j++){
            Union(j, start);
            Union((row-1)*col+j, end);
        }

        for(int i=row*col-1;i>=0;i--){
            int r = cells[i][0]-1;
            int c = cells[i][1]-1;
            grid[r][c] = 0; // mark the cell as blocked
            int key = r*col + c; // unique identifier for the current cell

            for(int k = 0; k < 4; k++){
                int nr = r+directions[k];
                int nc = c+directions[k+1]; // neighbor cell coordinates
                if(nr >= 0 && nr < row && nc >= 0 && nc < col && !grid[nr][nc]){
                    int nkey = nr*col + nc; // unique identifier for the neighbor cell
                    Union(key, nkey); // connect the current cell to the neighbor cell
                }
                if(find(start) == find(end)){
                    return i; // if the start and end are connected, the last day to cross is found
                }
            }
        }
        // If it reaches here, it means it's impossible to cross the grid
        return row*col-1;
    }
private:
    vector<int> directions = {1, 0, -1, 0, 1};
    bool canCross(int row, int col, vector<vector<int>> &cells, int day){
        vector<vector<int>> grid(row+1, vector<int> (col+1, 0));
        
        for(int i=0;i<day;i++){
            grid[cells[i][0]][cells[i][1]] = 1; //mark cells from the given list as blocked
        }

        queue<pair<int, int>> q;
        for(int i=1;i<=col;i++){
            if(grid[1][i]==0){
                q.push({1, i});
                grid[1][i] = 1; //mark as water
            }
        }

        while(!q.empty()){
            pair<int, int> top = q.front();
            q.pop();
            int r = top.first;
            int c = top.second;
            for(int i=0;i<4;i++){
                int nr = r + directions[i];
                int nc = c + directions[i+1];
                if(nr>0 and nc>0 and nr<=row and nc<=col and grid[nr][nc]==0){
                    grid[nr][nc] = 1;
                    if(nr==row) return true;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }

    vector<int> parent;
    int find(int x){
        return parent[x]<0 ? x : parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return;
        parent[y] = x;
    }
};