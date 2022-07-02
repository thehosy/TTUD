#include <bits/stdc++.h>

using namespace std;

int id = 0;
long long n, k, m;
long long x, y, temp;
long long ans = 1LL;
long long z;
vector<long long> vA(100);

long long product_mod(long long a, long long b) {
    if(a < b) swap(a, b);
    long long t = 0LL;
    while (b > 0) {
        if(b & 1) {
            t = (t + a) % m;
        }
        a = (a << 1) % m;
        b >>= 1; 
    }
    return t;
}

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
        y = (temp - product_mod(vA[i], y)) % m;
        y = y < 0? y + m: y; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int t;

    cin >> t;

    clock_t st = clock();
    for(int _ = 0; _ != t; ++_) {
        cin >> n >> k >> m;
        k = min(k, n - k);
  
        long long sd = n - k;
        ans = 1LL;
        x = 1LL;
        y = 0LL;
        id = 0;
        long long ans1 = 1LL, ans2 = 1LL;
        for(int i = 1; i <= k; ++i) {
            ans1 = product_mod(ans1 , (sd + i) % m);
            ans2 = product_mod(ans2 , i);
        }
        extendedEuclid(ans2, m);
        ans = product_mod(ans1, x);
        cout << ans << '\n';
    }

    clock_t ed = clock();
    cout << "Time: " << 1.0 * (ed - st) << " ms";
    return 0;
}
/*
15
1000000000000000000 100000 999999999999999877
12234 342 99971
236146 100000 1000000007
1000000000000000000 100000 999999999999999877
34646654 92378 1000000007
52365423767235465 10000 10000000000110007
3430000000000 92378 10000000000110007
10000000000000 92378 10000000000110007
100000000000000000 92378 1000000007
20000000000000000 100000 999999999999999877
1000000000000000000 100000 1000000007
1000000000000000000 100000 999999999999999877
10000000 100000 1000000007
252365423767235465 100000 10000000000110007
1000000000000000000 100000 999999999999999877*/