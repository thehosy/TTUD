#include <bits/stdc++.h>

#define PI 3.1415926535897932

using namespace std;

int N, F;
long long r[10007];
long long maxVolume = 0LL;
double ans;

bool check(double mid) {
    int pieces = 0;
    int temp;
    for(int i = 0; i < N; i++) {
        pieces += int(r[i] * PI / mid);
            if(pieces > F) return true;
    }
    return false;
}

void solve() {
    double lo = 0.0;
    double hi = double(maxVolume) * PI;

    while(abs(hi - lo) >= 1e-7) {
        // cout << "lo and hi: " << lo << ", " << hi << '\n';
        double mid = (lo + hi) / 2;
        if(check(mid)) {
            ans = mid;
            lo = mid;
        } else {
            hi = mid;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("out.txt", "w", stdout);
    int t;

    cin >> t;

    for(int _ = 0; _ < t; ++_) {
        cin >> N >> F;
        for(int i = 0; i < N; ++i) {
            cin >> r[i];
            r[i] = r[i] * r[i];
            maxVolume = max(maxVolume, r[i]);
        }

        solve();
        cout << setprecision(6) << fixed << ans << '\n';
    }

    return 0;
}