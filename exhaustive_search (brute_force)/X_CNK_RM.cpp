#include <bits/stdc++.h>

using namespace std;

const long long m = 1e9+7LL;

int id = 0;
long long n, k;
long long x = 1LL, y, temp;
long long ans;
vector<long long> vA(100);

void extendedEuclid(long long A, long long B) {
    while (B != 0) {
        vA[id] = A / B;
        temp = B;
        B = A - B * vA[id];
        A = temp;
        ++id;
    }
    for(int i = id - 1; i >= 0; --i) {
        temp = x;
        x = y;
        y = (temp - (vA[i] * y) % m) % m;
        y = y < 0? y + m: y; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);


    cin >> k >> n;

    clock_t st = clock();

    k = min(k, n - k);

    long long ans1 = 1LL;
    long long ans2 = 1LL;
    long long sd = n - k;

    for(int i = 1; i <= k; ++i) {
        ans1 = (ans1 * (sd + i)) % m;
        ans2 = (ans2 * i) % m;
    }
    extendedEuclid(ans2, m);
    ans = (ans1 * x) % m;
    cout << ans << '\n';

    clock_t ed = clock();
    cout << "Time: " << 1.0 * (ed - st) << " ms";
    return 0;
}