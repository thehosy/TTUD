#include <bits/stdc++.h>

#define M 32
using namespace std;

int N;
int K;
int Q;
int d[M];
int Y[M];
int X[M];
bool visited[M];
int load[M];
int segments = 0;
int cnt = 0;

bool checkY(int v, int k) {
    if(visited[v]) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}

bool checkX(int u, int k) {
    if(u == 0) return true;
    if(visited[u]) return false;
    if(load[k] + d[u] > Q) return false;

    return true;
}

void TryX(int v, int k) {
    for(int u = 0; u <= N; u++) {
        if(checkX(u, k)) {
            X[v] = u;
            segments+=1;
            load[k] += d[u];
            visited[u] = true;
            if(u == 0) {
                if(k == K) {
                    if (segments == N + K) {
                        cnt++;
                    }
                } else {
                    TryX(Y[k + 1], k + 1);
                }

            } else {
                TryX(u, k);
            }
            segments -= 1;
            load[k]-= d[u];
            visited[u] = false;
        }
    }
}

void TryY(int k) {
    for(int v = Y[k - 1] + 1; v <= N; v++) {
        if(checkY(v, k)) {
            Y[k] = v;
            visited[v] = true;
            segments += 1;
            load[k] += d[v];
            if(k == K) {
                TryX(Y[1], 1);
            } else {
                TryY(k + 1);
            }
            visited[v] = false;
            segments -= 1;
            load[k] -= d[v];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); // fast io

    // freopen("input.txt", "r", stdin);

    cin >> N >> K >> Q;
    for(int i = 1; i <= N; i++)
        cin >> d[i];

        int bv;

        for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            cin >>bv;
        }
    }


    TryY(1);

    cout << cnt;
    return 0;
}

// 0 - 1 - 2 - 0
// 0 - 4 - 3 - 0