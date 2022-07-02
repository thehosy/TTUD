#include <bits/stdc++.h>

using namespace std;

long long N, M;

int a[1000007];
long long m = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> a[i];
        if(a[i] > m)
            m = a[i];
    }

    long long l = 1, h = m - 1, mid;
    long long ans = 0, t;
    while(l <= h) {
        t = 0;
        int mid = (l + h) >> 1;
        for(int i = 0; i < N; i++) {
            if(a[i] > mid) {
                t += a[i] - mid;
            }
        }
        if(t == M) {
            ans = mid;
            break;
        }
        if(t > M) {
            l = mid + 1;
            ans = mid;
        }
        else h = mid - 1;
    }

    cout << ans;

    return 0;
}