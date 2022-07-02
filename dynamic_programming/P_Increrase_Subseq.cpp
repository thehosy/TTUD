#include <bits/stdc++.h>

using namespace std;

int n;
int a[10007];
int b[10007];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    b[0] = INT_MIN;

    int res = 0;

    for(int i = 0; i < n; i++) {
        int k = lower_bound(b, b + res + 1, a[i]) - b; // int min, 1, 3, ...... 

        b[k] = a[i];
        res = max(res, k);
    }

    cout << res;

    return 0;
}