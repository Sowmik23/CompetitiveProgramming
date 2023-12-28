// 1202. Smallest String With Swaps

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        

        //DFS solution: TLE
        //BFS : Accepted
        int n = s.size();
        vector<vector<int>> adjacencyList(n);
        vector<bool>visited(n, false);

        for(auto& pair: pairs){
            adjacencyList[pair[0]].push_back(pair[1]);
            adjacencyList[pair[1]].push_back(pair[0]);
        }

        vector<vector<int>> lists;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                vector<int> tmpList = bfs(s, adjacencyList, visited, i);
                lists.push_back(tmpList);
            }
        }

        string output(n, ' ');
        for(auto& tmp: lists){
            vector<char> str;
            for(auto& idx: tmp){
                str.push_back(s[idx]);
            }
            
            sort(str.begin(), str.end());
            sort(tmp.begin(), tmp.end());
            for(int j=0;j<tmp.size();j++){
                output[tmp[j]] = str[j];
            }
        }
        
        return output;
    }
private:
    vector<int> bfs(string s, vector<vector<int>> &adjacencyList, vector<bool> &visited, int idx){

        vector<int> indices;
        stack<int> stk;
        visited[idx] = true;
        indices.push_back(idx);
        stk.push(idx);

        while(!stk.empty()){
            int top = stk.top();
            stk.pop();

            for(auto& nIdx: adjacencyList[top]){
                if(!visited[nIdx]){
                    visited[nIdx] = true;
                    indices.push_back(nIdx);
                    stk.push(nIdx);
                }
            }
        }
        return indices;
    }
};








class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        

        //DFS solution: TLE
        int n = s.size();
        vector<vector<int>> adjacencyList(n);
        vector<bool>visited(n, false);

        for(auto& pair: pairs){
            adjacencyList[pair[0]].push_back(pair[1]);
            adjacencyList[pair[1]].push_back(pair[0]);
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                indices.clear();
                str = "";
                dfs(s, adjacencyList, visited, i);

                sort(str.begin(), str.end());
                sort(indices.begin(), indices.end());
                for(int j=0;j<indices.size();j++){
                    s[indices[j]] = str[j];
                }
            }
        }
        
        return s;
    }
private:
    vector<int> indices;
    string str = "";
    void dfs(string s, vector<vector<int>> &adjacencyList, vector<bool> &visited, int idx){
        visited[idx] = true;
        str+=s[idx];
        indices.push_back(idx);
        for(auto& nIdx: adjacencyList[idx]){
            if(!visited[nIdx]){
                dfs(s, adjacencyList, visited, nIdx);
            }
        }
    }
};
// bacd