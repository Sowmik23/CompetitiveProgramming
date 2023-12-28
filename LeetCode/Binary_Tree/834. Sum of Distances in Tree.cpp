class Solution {
public:
    vector<unordered_set<int>> tree;
    vector<int> res, cnt;

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        //two dfs: Time: O(n)
        tree = vector<unordered_set<int>> (n);
        res = vector<int> (n,   0);
        cnt = vector<int> (n, 1);

        for(auto& e: edges){
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }

        dfs1(0, -1);
        dfs2(0, -1);

        return res;
    }
private:
    void dfs1(int root, int pre){
        for(auto i: tree[root]){
            if(i==pre) continue ;
            dfs1(i, root);
            cnt[root] += cnt[i];
            res[root] += res[i]+cnt[i];
        }
    }
    void dfs2(int root, int pre){
        for(auto i: tree[root]){
            if(i==pre) continue;
            res[i] =  res[root] - cnt[i] + cnt.size() - cnt[i];
            dfs2(i, root);
        }
    }
};
