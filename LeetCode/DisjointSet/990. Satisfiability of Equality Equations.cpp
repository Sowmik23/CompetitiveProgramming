class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> sz;
    int groups;
    bool equationsPossible(vector<string>& equations) {

        int n = 26;
        init(n);

        sort(equations.begin(), equations.end(), [](auto& a, auto& b){return a[1]>b[1];});
        for(int i=0;i<equations.size();i++){
            //cout<<equations[i]<<" ";
            int a = equations[i][0]-'a';
            int b = equations[i][3]-'a';
            char ch = equations[i][1];

            if(ch=='='){
                uniion(a, b);
            }
            else {
                if(isSameGroup(a, b)) return false;
            }
        }
       // cout<<endl;
        return true;
    }
private:
    void init(int n){
        groups = n;
        parent = vector<int> (n);
        rank = vector<int> (n, 0);
        sz = vector<int> (n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    void uniion(int a, int b){
        int xa = find(a);
        int xb = find(b);

        //if they are already in same set
        if(xa==xb) return;

        //put smaller ranked iteem into  larger one
        if(rank[xa]<rank[xb]) {
            parent[xa] = xb;
            sz[xb]+=sz[xa];
        }
        else if(rank[xa]>rank[xb]){
            parent[xb]  = xa;
            sz[xa]+=sz[xb];
        }
        else { //rank are same so incremeent rank
            parent[xb] = xa;
            sz[xa]+=sz[xb];
            rank[xa]++;
        }
        groups--;
    }
    int find(int a){
        if(parent[a]!=a) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }
    int numOfGroups(){ return groups;}
    bool isSameGroup(int a, int b) {
        int x = find(a);
        int y = find(b);
        cout<<x<<" "<<y<<endl;
        return x==y; }
    int sizeOfGroup(int a) {
        return sz[find(a)];
    }
};
