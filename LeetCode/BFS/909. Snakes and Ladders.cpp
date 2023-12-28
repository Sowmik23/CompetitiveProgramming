class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {


        //Time complexity: O(n^2)
        //Space: complexity: O(n^2)

        int n = board.size();
        vector<pair<int, int>> cells(n*n+1);

        int label = 1;

        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0); //0, 1, 2, 3.....n-1

        for(int row = n-1;row>=0;row--){
            for(int col: columns){
                cells[label++] = {row, col};
            }
            reverse(columns.begin(), columns.end()); //nice trick <--this line: I was actually anxious of handling this
        }

        //now cells becomes
        // 0 -> 0,0, 0,1, 0,2, 0,3
        // 1 -> 1,4, 1,5, 1,6, 1,7
        // 2 -> 2,8, 2,9, 2,10, 2,11

        vector<int> dist(n*n+1, -1);
        queue<int> q;
        dist[1]=0;
        q.push(1);
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int i = curr+1;i<=min(curr+6, n*n);i++){
                auto [row, col] = cells[i];
                int destination = board[row][col]!=-1 ? board[row][col] : i;
                if(dist[destination]==-1){
                    dist[destination] = dist[curr]+1;
                    q.push(destination);
                }
            }
        }
        return dist[n*n];
    }
};
