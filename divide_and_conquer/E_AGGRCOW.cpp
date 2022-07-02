#include <bits/stdc++.h>

using namespace std;

int N, C;
long long ans, maxPos;
long long stall[100007];

bool check(long long mid) {
    int lasId = 0;
    int filled = 1;
    for(int i = 1; i < C; i++) {
        int lo = lasId + 1;
        int hi = N - 1;
        int tmpId = -1;
        while(lo <= hi) {
            int md = (lo + hi) >> 1;
            if(stall[md] - stall[lasId] >= mid) {
                tmpId = md;
                hi = md - 1;
            } else lo = md + 1;
        }
        if(tmpId == -1)
            return false;
        lasId = tmpId;
    }
    return true;
}

void solve() {
    int lo = 1, hi = maxPos;

    while(lo <= hi) {
        long long mid = (lo + hi) >> 1;
        if(check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans <<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int _ = 0; _ < t ; _++) {
        maxPos = 0;
        cin >> N >> C;
        for(int i = 0; i < N ; i++) {
            cin >> stall[i];
            maxPos = max(maxPos, stall[i]);
        }
        sort(stall, stall + N);

        solve();
    }

    return 0;
}