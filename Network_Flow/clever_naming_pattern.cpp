#include <algorithm>
#include <iostream>
#include <cstring>
#include <cctype>
#include <limits>
#include <string>
#include <queue>
#include <map>
using namespace std;
 
#define N 54
typedef map<int, int>::iterator itr;
map<int, int> res[N];
int parent[N], s = N - 2, t = N - 1;
 
bool bfs() {
    queue<int> q;
    q.push(s);
    memset(parent, -1, sizeof parent);
    parent[s] = s;
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (u == t)
            return true;
        for (itr it = res[u].begin(); it != res[u].end(); ++it)
            if (parent[it->first] == -1 && it->second > 0)
                parent[it->first] = u, q.push(it->first);
    }
    return false;
}
 
int maxFlow() {
    int mf = 0, f, v;
    while (bfs()) {
        // min
        v = t;
        f = numeric_limits<int>::max();
        while (parent[v] != v)
            f = min(f, res[parent[v]][v]), v = parent[v];
        // update
        v = t;
        mf += f;
        while (parent[v] != v)
            res[parent[v]][v] -= f, res[v][parent[v]] += f, v = parent[v];
    }
    return mf;
}
 
int main() {
    string str;
    int nCase, nProblem;
    map<char, string> pNames[28];
    cin >> nCase;
    for (int caseI = 0; caseI < nCase; ++caseI) {
        // init
        cin >> nProblem;
        for (int i = 0; i < N; ++i)
            res[i].clear();
        for (int i = 0; i < nProblem; ++i) {
            pNames[i].clear();
            res[s][26 + i] = 1;
            res[i][t] = 1;
        }
        // input
        for (int i = 0, nName; i < nProblem; ++i) {
            cin >> nName;
            for (int j = 0; j < nName; ++j) {
                cin >> str;
                str[0] = toupper(str[0]);
                for (int k = 1; k < str.length(); ++k)
                    str[k] = tolower(str[k]);
                pNames[i][str[0]] = str;
                res[str[0] - 'A' + 26][i] = 1;
            }
        }
        // solve
        maxFlow();
        cout << "Case #" << (caseI + 1) << ":\n";
        for (int i = 0; i < nProblem; ++i)
            for (itr it = res[i + 26].begin(); it != res[i + 26].end(); ++it)
                if (!it->second) {
                    cout << pNames[it->first][i + 'A'] << endl;
                    break;
                }
    }
    return 0;
}
