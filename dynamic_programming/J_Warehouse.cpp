#include <bits/stdc++.h>

using namespace std;

int N, T, D;
int a[1007];
int t[1007];
int dp[1007][107];
int res = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> T >> D;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= N; i++) {
        cin >> t[i];
    }

    for(int i = 1; i <= N; i++) {
        for(int k = 1; k <= T; k++) {
            if(k >= t[i]) {
                int temp = 0;
                for(int j = i - D; j <= i - 1; j++) {
                    if(j >= 0) {
                        temp = max(temp, dp[j][k - t[i]] + a[i]);
                    }
                }
                dp[i][k] = temp;
                res = max(res, temp);
            }
        }
    }

    cout << res;

    return 0;
}