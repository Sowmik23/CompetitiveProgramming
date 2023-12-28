class Solution {
public:
    class UnionFind {
        public:
            int totalComponents;
            vector<int> parents, rank;
            UnionFind(int n){
                totalComponents = n;
                parents = vector<int> (n);
                rank = vector<int> (n);
                for(int i=0;i<n;i++){
                    parents[i] = i;
                }
            }
            void Union(int x, int y){
                int a = find(x);
                int b = find(y);

                // if(rank[a]<rank[b]){
                //     parents[b] = a;
                // }
                // else if(rank[a]>rank[b]){
                //     parents[a] = b;
                // }
                // else {
                //     parents[b] = a;
                //     rank[a]++;
                // }
                parents[max(a, b)] = min(a, b);
                totalComponents--;
            }
            int find(int x){
                if(parents[x]!=x) parents[x] = find(parents[x]);
                return parents[x];
            }
            bool isConnected(int x, int y){
                return find(x)==find(y);
            }
    };
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {

        UnionFind *uf = new UnionFind(26);

        for(int i=0;i<s1.size();i++){
            uf->Union(s1[i]-'a', s2[i]-'a');
        }

        string res = "";
        for(int i=0;i<baseStr.size();i++){
            int x = uf->find(baseStr[i]-'a');
            res+='a'+x;
        }

        return res;
    }
};
