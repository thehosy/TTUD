#include <bits/stdc++.h>

using namespace std;

bool conflict[32][32];

vector<int> v[32];
int assign[32];
vector<int> load[16];
int m, n, ans = 50;
bool mark[32];

bool check(int i, int u) {
    if(mark[i]) return false;
    for(int j: load[u]){
        if(conflict[i][j]) return false;
    }
    return true;
} 

void solve(int k) {
    int l = v[k].size();
    for(int j = 0; j < l; ++j) {
        if(check(k, v[k][j])){
            if(load[v[k][j]].size() + 1 >= ans)
                continue;
            assign[k] = v[k][j];
            load[v[k][j]].push_back(k);
            mark[k] = true;
            if(k == n){
                int temp = 0;
                for(int ii = 0; ii < m; ii++) {
                    temp = max(temp, (int)load[ii].size());
                }
                ans = min(ans, temp);
            }
            else solve(k + 1);
            load[v[k][j]].pop_back();
            mark[k] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> m >> n;
    for(int i = 0, k; i < m; ++i) {
        cin >> k;
        for(int j = 0, t; j < k; ++j) {
            cin >> t;
            v[t].push_back(i);
        }
    }

    int k;
    cin >> k;
    for(int i = 0, u, v, t; i < k; ++i) {
        cin >> u >> v;
        conflict[u][v] = true;
        conflict[v][u] = true;
    }

    solve(1);

    ans < 50? cout << ans : cout << -1;

    return 0;
}