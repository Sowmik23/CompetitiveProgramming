#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD n00000007
#define EPS 1e-9
#define  MAX_V 100
#define EQUALE(a, b) (fabs(a - b) < ESP)
using namespace std;
int f, s, t;
int np, nk, a, b;
vector<unordered_map<int, int>> res(1200);
vector<int> p;
void augment(int v, int minedge) {
    if (v == s) {
        f = minedge;
        return;
    }
    if (p[v] != -1) {
        augment(p[v], min(minedge, res[p[v]][v]));
        res[p[v]][v] -= f, res[v][p[v]] += f;
    }
}
int solve() {
    int mf = 0, u;
    while (1) {
        f = 0, p.assign(1200, -1);
        queue<int> q;
        bitset<1200> v(0);
        v[s] = 1, q.push(s);
        while (!q.empty()) {
            u = q.front(), q.pop();
            if (u == t)
                break;
            unordered_map<int, int>::iterator it;
            for (it = res[u].begin(); it != res[u].end(); it++) {
                if (it->second > 0 && !v[it->first])
                    q.push(it->first), p[it->first] = u, v[it->first] = 1;
            }
        }
        augment(t, 99999999);
        if (f == 0)
            return mf;
        mf += f;
    }
    return mf;
}
void printSol() {
    for (int i = np + 1; i <= np + nk; i++) {
        unordered_map<int, int>::iterator it;
        for (it = res[i].begin(); it != res[i].end(); it++) {
            if (it->first != np + nk + 1 && it->second != 0)
                cout << it->first << " ";
        }
        cout << endl;
    }
}
int main(int argc, char **argv) {
    freopen("in.txt", "r", stdin);
    while (1) {
        cin >> nk >> np;
        if (nk + np == 0)
            return 0;
        for (int i = 0; i < 1200; i++)
            res[i].clear();
        int sum = 0;
        for (int i = np + 1; i <= np + nk; i++) {
            cin >> a;
            res[i][np + nk + 1] = a;
            sum += a;
        }
        for (int i = 1; i <= np; i++) {
            res[0][i] = 1;
            cin >> a;
            for (int j = 0; j < a; j++) {
                cin >> b;
                res[i][b + np] = 999999;
            }
        }
        s = 0, t = np + nk + 1;
        int x = solve();
        if (sum == x) {
            cout << 1 << endl;
            printSol();
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
