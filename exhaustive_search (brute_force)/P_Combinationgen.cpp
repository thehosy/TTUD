#include <bits/stdc++.h>

using namespace std;

vector<int> a(10007);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int n, m;

    cin >> n >> m;

    for(int i = 1; i <= m; ++i)
        cin >> a[i];

    int r = m;

    while(r > 0 and a[r] == n - m + r)
        --r;

    if(r == 0){
        cout << -1;
    } else {
        ++a[r];
        for(int i = r + 1; i <= m; ++i)
            a[i] = a[i - 1] + 1;
        for(int i = 1; i <= m; ++i)
            cout << a[i] << ' ';
    }


    return 0;
}