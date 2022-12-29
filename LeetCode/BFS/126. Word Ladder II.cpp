class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        //interesting and important problem

//         vector<vector<string>> res;
//         unordered_set<string> words(wordList.begin(), wordList.end());
//         queue<vector<string>> q;
//         unordered_set<string> visited;

//         q.push({beginWord});

//         while(!q.empty()){
//             int size = q.size();
//             while(size--){
//                 vector<string> top = q.front();
//                 q.pop();

//                 string last = top.back();
//                 for(int i=0;i<last.size();i++){
//                     string tmp = last;
//                     for(char ch='a';ch<='z';ch++){
//                         tmp[i] = ch;
//                         if(words.find(tmp)!=words.end()){
//                             vector<string> newWords = top;
//                             newWords.push_back(tmp);
//                             visited.insert(tmp);
//                             if(tmp==endWord){
//                                 res.push_back(newWords);
//                             }
//                             else {
//                                 q.push(newWords);
//                             }
//                         }
//                     }
//                 }
//             }
//             for(auto& word: visited) words.erase(word);
//         }

//         return res;

        unordered_map<string, int> nodeLadder; // node, ladder
        for (const string& word : wordList)
          nodeLadder[word] = INT_MAX;
        if (nodeLadder.count(endWord) == 0)
          return {};

        unordered_map<string, vector<string>> graph;
        BFS(beginWord, endWord, nodeLadder, graph);

        vector<vector<string>> solution;
        vector<string> state { endWord };
        DFS(graph, beginWord, solution, state, endWord);

        for (auto& path : solution)
          reverse(path.begin(), path.end());

        return solution;
    }
private:
  void DFS(unordered_map<string, vector<string>>& graph, string& target,
           vector<vector<string>>& solution, vector<string>& state, const string& node) {

    if (node == target) {
      solution.emplace_back(state);
      return;
    }

    for (const string& neighbor : graph[node]) {
      state.emplace_back(neighbor);
      DFS(graph, target, solution, state, neighbor);
      state.pop_back();
    }
  }

  void BFS(string& beginWord, string& endWord, unordered_map<string, int>& nodeLadder,
           unordered_map<string, vector<string>>& graph) {

    queue<string> queue;
    queue.push(beginWord);

    int ladder = 1;
    while (queue.size()) {
      int size = queue.size();

      while (size--) {
        string node = queue.front(), new_node = node;
        queue.pop();

        for (char& c : new_node) {
          char backup_c = c;
          for (int new_c = 'a'; new_c <= 'z'; new_c++) {
            c = new_c;
            if (node != new_node and nodeLadder.count(new_node) and nodeLadder[new_node] >= ladder) {
              graph[new_node].emplace_back(node);
              if (nodeLadder[new_node] == ladder)
                continue;
              nodeLadder[new_node] = ladder;
              if (new_node != endWord)
                queue.emplace(new_node);
            }
          }
          c = backup_c;
        }
      }
      ladder++;
    }
  }
};
