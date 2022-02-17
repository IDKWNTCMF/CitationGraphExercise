#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int n, const vector<vector<int> > &g, const vector<bool> &s, vector<int> &dist) {
    queue<int> q;
    for (int v = 1; v <= n; v++) {
        if (s[v]) {
            q.push(v);
            dist[v] = 0;
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : g[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}

void solve(const char *inputFile) {
    freopen(inputFile, "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
    }
    vector<bool> s1(n + 1, false), s2(n + 1, false);
    int k1, k2;
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        int v;
        cin >> v;
        s1[v] = true;
    }
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        int v;
        cin >> v;
        s2[v] = true;
    }
    vector<int> dist1(n + 1, -1), dist2(n + 1, -1);
    bfs(n, g, s1, dist1);
    bfs(n, g, s2, dist2);
    vector<vector<int> > sorted(2 * n);
    for (int v = 1; v <= n; v++) {
        if (dist1[v] != -1 && dist2[v] != -1) {
            sorted[dist1[v] + dist2[v]].push_back(v);
        }
    }
    for (int d = 0; d < 2 * n; d++) {
        for (auto v : sorted[d]) {
            cout << v << '\n';
        }
    }
}

int main() {
    const char *inputFile = "input.txt";
    solve(inputFile);
    return 0;
}
