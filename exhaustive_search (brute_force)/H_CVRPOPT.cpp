#include <bits/stdc++.h>

using namespace std;

int n, K, Q;
int d[16];
int Y[8];
int X[16];
int load[8];
int c[32][32];
bool visited[16];
int f_min = 1e9;
int f_temp = 0;
int segments = 0;
int cm = 1e9;

bool checkX(int u, int k) {
    if(u == 0) return true;
    if(visited[u]) return false;
    if(load[k] + d[u] > Q) return false;

    return true;
}

bool checkY(int v, int k) {
    if(visited[v]) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}

void solveX(int v, int k) {
    for(int u = 0; u <= n; u++) {
        if(checkX(u, k)) {
            X[v] = u;
            segments += 1;
            load[k] += d[u];
            visited[u] = true;
            f_temp += c[v][u];

            if(u == 0) {
                if(k == K) {
                    if (segments == n + K) {
                        f_min = min(f_min, f_temp);
                    }
                } else {
                    int z = n + K - segments;
                    int t = f_temp + cm * z;
                    if(t < f_min)
                        solveX(Y[k + 1], k + 1);
                }
            } else {
                int z = n + K - segments;
                int t = f_temp + cm * z;
                if(t < f_min)
                    solveX(u, k);
            }

            segments -= 1;
            load[k]-= d[u];
            visited[u] = false;
            f_temp -= c[v][u];
        }
    }
}

void solveY(int k) {
    for(int v = Y[k - 1] + 1; v <= n; v++) {
        if(checkY(v, k)) {
            Y[k] = v;
            visited[v] = true;
            f_temp += c[0][v];
            load[k] += d[v];
            segments += 1;

            if(k == K) {
                solveX(Y[1], 1);
            } else solveY(k + 1);

            visited[v] = false;
            segments -= 1;
            load[k] -= d[v];
            f_temp -= c[0][v];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt","r", stdin);

    cin >> n >> K >> Q;

    for(int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            cin >> c[i][j];
            if(i != j) cm = min(cm, c[i][j]);
        }
    }

    solveY(1);

    cout << f_min;

    return 0;
}