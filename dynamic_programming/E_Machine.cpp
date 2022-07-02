#include <bits/stdc++.h>

using namespace std;

int n;

struct Node {
    int s, t, pro;
};

Node p[2000001];
int maxAmount[2000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t_min = 2000001, s_max = 0, t_max = 0;
    cin >> n;
    for(int i = 0; i != n; ++i) {
        cin >> p[i].s >> p[i].t;
        p[i].pro = p[i].t - p[i].s;
        t_min = min(t_min, p[i].t);
        s_max = max(s_max, p[i].s);
        t_max = max(t_max, p[i].t);
    }

    if(t_min >= s_max) {
        cout << "-1";
    }
    else {
        maxAmount[0] = 0;
        for(int i = 0; i < n; i++) {
            if(maxAmount[p[i].t])
                maxAmount[p[i].t] = max(maxAmount[p[i].t], p[i].t - p[i].s);
            else maxAmount[p[i].t] = p[i].t - p[i].s;
        }

        for(int i = 1; i <= t_max; i++) {
            maxAmount[i] = max(maxAmount[i - 1], maxAmount[i]);
        }
        int res = -1;
        for(int i = 0; i < n; i++) {
            res = max(res, p[i].t - p[i].s + maxAmount[p[i].s - 1]);
        }

        cout << res;
    }
    return 0;
}