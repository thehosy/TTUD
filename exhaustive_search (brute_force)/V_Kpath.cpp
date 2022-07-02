#include <bits/stdc++.h>

using namespace std;

int n, m, k; 
int paths = 0;
int cnt = 0;

vector<int> e[64];
bool visited[64];

void solve(int id) {
    int sz = e[id].size();
    for(int i = 0; i < sz; i++) {
        if(!visited[e[id][i]]) {
            visited[e[id][i]] = true;
            ++paths;
            if(paths == k) {
                // cout << X[0];
                // for(int j = 1; j <= paths; j++) {
                //     cout << " -> " << X[j];
                // }
                // cout << '\n';
                ++cnt;
            } else solve(e[id][i]);

            --paths;
            visited[e[id][i]] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    // freopen("input.txt", "r", stdin);

    cin >> n >> k >> m;

    for(int i = 0, u, v; i != m; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i) {
        visited[i] = true;
        solve(i);
        visited[i] = false;
    }

    cout << (cnt >> 1);

    return 0;
}