#include <bits/stdc++.h>

using namespace std;

vector<int> s(10007);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    int n;

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> s[i];

    int i = n - 2;
    while(i > -1 and s[i] > s[i + 1])
        --i;
    if(i == -1)
        cout << -1;
    else {
        int j = n - 1;
        while (s[j] < s[i])
            --j;
        swap(s[i], s[j]);
        for(int l = i + 1, r = n - 1; l < r; ++l, --r)
            swap(s[l], s[r]);
        
        for(int i = 0; i < n; ++i)
            cout << s[i] << ' ';
    }

    return 0;
}