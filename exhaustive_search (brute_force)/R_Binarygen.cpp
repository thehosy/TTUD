#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    int n = 0;
    string s;
    cin >> n;
    cin >> s;

    int i = n - 1;

    while (i > -1 and s[i] == '1')
        --i;
    if(i == -1)
        cout << -1;
    else {
        s[i] = '1';
        for(int j = i + 1; j < n; j++)
            s[j] = '0';
        cout << s;
    }

    return 0;
}