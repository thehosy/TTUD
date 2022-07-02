#include <bits/stdc++.h>

using namespace std;
int m, k;
long long p[512];
int group[512];
long long p_max, p_sum, ans;

bool check(long long mid) {
    int id = 1;
    long long tmp = 0;
    for(int i = m - 1; i != -1; --i) {
        if(tmp + p[i] <= mid && i > k - id - 1) {
            tmp += p[i]; 
        } else {
            ++id;
            tmp = p[i];
        }
        group[i] = id;
    }
    return id == k;
}

void  solve() {
    long long lo = p_max;
    long long hi = p_sum;
    
    while (lo <= hi) {
        long long mid = (lo + hi) >> 1;
        if(check(mid)) {
            ans = mid;
            hi = mid - 1; 
        } else {
            lo = mid + 1;
        }
    }
    check(ans);
    for(int i = 0; i < m - 1; i++) {
        cout << p[i] << ' ';
        if(group[i] != group[i + 1]) 
            cout << " / ";
    }
    cout << p[m - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    for(int _ = 0; _ < t; ++_) {
        p_max = 0, p_sum = 0;
        cin >> m >> k;
        for(int i = 0; i < m; i++) {
            cin >> p[i];
            p_max = max(p_max, p[i]);
            p_sum += p[i];
        }
        solve();
    }
    return 0;
}