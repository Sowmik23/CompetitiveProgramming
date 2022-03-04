class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        
        //BFS: Time: O(VlogE*m*26)
        //O(list_length * word_length * lookup_time)
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        queue<string> q;
        q.push(beginWord);
        
        int ladder = 1;
        
        while(!q.empty()){
            int n = q.size();
            for(int k=0;k<n;k++){
                string top = q.front();
                q.pop();

                if(top==endWord) return ladder;

                st.erase(top);

                for(int i=0;i<top.size();i++){
                    char ch = top[i];
                    for(int j=0;j<26;j++){
                        top[i] = 'a'+j;
                        if(st.find(top)!=st.end()){
                            q.push(top);
                        }
                    }
                    top[i] = ch;
                }
            }
            ladder++;
        }
        
        return 0;
    }
};
