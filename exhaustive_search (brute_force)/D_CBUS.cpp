#include <bits/stdc++.h>

using namespace std;

int e[32][32];
int c = 0, l, n, k = 1;
int ans = 1e9, cm = 1e9, temp = 0;
int x[32];
bool mark[32];

void solve(int v) {
    for(int i = 1; i < l; ++i) {
        if(!mark[i]) {
            if(i > n) {
                if(mark[i - n] and c > 0)
                    --c;
                else continue;
            } else {
                if(c < k)
                    ++c;
                else continue;
            }
 
            x[v] = i;
            temp += e[x[v - 1]][x[v]];
            mark[i] = true;
            
            if (v == l - 1) {
                if(c == 0) {
                    ans = min(ans, temp + e[x[v]][0]);
                }
            } else {
                int tempf = temp + cm * (l - v);
                if(tempf < ans)
                    solve(v + 1);
            }

            if(i > n) ++c;
            else --c;
            temp -= e[x[v - 1]][x[v]];
            mark[i] = false;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> n;
    l = n << 1 | 1;

    for(int i = 0; i < l; ++i)
        for(int j = 0; j < l; ++j) {
            cin >> e[i][j];
            if(i != j) cm = min(cm, e[i][j]);
        }

    x[0] = 0;
    mark[0] = true;

    solve(1);

    cout << ans;

    return 0;
}