#include <bits/stdc++.h>

using namespace std;

int len[10007][10007];

int arr1[10007];
int arr2[10007];

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; ++i) cin >> arr1[i];
    for(int i = 0; i < m; ++i) cin >> arr2[i];

    for(int i = 0; i < n; ++i) len[i][0] = arr1[i] == arr2[0];
    for(int i = 0; i < m; ++i) len[0][i] = arr2[i] == arr1[0];

    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < m; j++) {
            if(arr1[i] == arr2[j]) {
                len[i][j] = len[i - 1][j - 1] + 1;
            } else {
                len[i][j] = max(len[i - 1][j], len[i][j - 1]);
            }
        }
    }

    cout << len[n - 1][m - 1];

    return 0;
}