// 864. Shortest Path to Get All Keys
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {

        /*
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<char, int> key_bit;
        int bit_start = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (islower(grid[i][j]))
                    key_bit[grid[i][j]] = bit_start++;
            }
        }

        int form_end = (1 << bit_start) - 1;
        int form_size = (1 << bit_start);

        vector<vector<vector<bool>>> memo(m, vector<vector<bool>>(n, vector<bool>(form_size, false)));

        vector<int> start;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@')
                    start = { i, j, 0 }; // 0 denoting no key state
            }
        }

        queue<vector<int>> q;
        q.push(start);
        int Ashish = 0; // Step counter

        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                int row = q.front()[0];
                int col = q.front()[1];
                int form = q.front()[2];
                q.pop();

                // Check if out of bounds
                if (row < 0 || row >= m || col < 0 || col >= n)
                    continue;

                // Check if position is blocked
                if (grid[row][col] == '#')
                    continue;

                // Check if the key is required but not collected
                if (isupper(grid[row][col])) {
                    if ((form & (1 << key_bit[tolower(grid[row][col])])) == 0)
                        continue;
                }

                // If the position contains a key, collect it
                if (islower(grid[row][col])) {
                    form = form | (1 << key_bit[grid[row][col]]);
                }

                // If all keys are collected, return the step count
                if (form == form_end)
                    return Ashish;

                // If the position and form combination has been visited, continue to the next iteration
                if (memo[row][col][form])
                    continue;
                memo[row][col][form] = true;

                // Add adjacent positions to the queue
                q.push({ row + 1, col, form });
                q.push({ row - 1, col, form });
                q.push({ row, col + 1, form });
                q.push({ row, col - 1, form });
            }
            Ashish++; // Increment step count
        }
        return -1;
        */

    /*
    This is a challenging problem that requires utilizing a combination of breadth-first search (BFS) and bit manipulation to represent the state of keys. The keys and locks are represented by lower case and upper case English alphabets respectively, and each state is a combination of current position and keys collected. BFS can be used to search for all reachable states from the current state, and a queue is used to store all states that will be visited in the future.
    This solution maintains a queue of the current position and the keys we have. Each time we pop from the queue, we try to move to 4 different directions, and we add new states to the queue if the following conditions are satisfied:

 - The new position is inside the grid and is not a wall.
 - If the new position is a lock, we have the corresponding key.
 - We have not visited the new position with the keys we have.
This solution guarantees the shortest path because it is a breadth-first search. Whenever we find a state that we have all keys, we can return the steps of that state immediately.
    */
    
        int startX = 0, startY = 0, maxKey = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(64, 0)));
        queue<vector<int>> q;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '@'){
                    startX = j;
                    startY = i;
                }
                if(grid[i][j] >= 'a' && grid[i][j] <= 'f')
                    maxKey = max(maxKey, grid[i][j] - 'a' + 1);
            }
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        q.push({startY, startX, 0, 0});
        while(!q.empty()){
            auto t = q.front(); q.pop();
            if(t[2] == (1 << maxKey) - 1) return t[3]; // all keys have been collected
            for(auto dir : dirs){
                int x = t[1] + dir[0], y = t[0] + dir[1];
                int key = t[2];
                if(x < 0 || x >= n || y < 0 || y >= m || grid[y][x] == '#') continue; 
                char c = grid[y][x];
                if(c >= 'a' && c <= 'f') key |= 1 << (c - 'a'); // collect new key
                else if(c >= 'A' && c <= 'F' && !(key & (1 << (c - 'A')))) continue; // can't pass the lock
                if(!visited[y][x][key]){
                    visited[y][x][key] = 1;
                    q.push({y, x, key, t[3] + 1});
                }
            }
        }
        return -1;
    }
};
