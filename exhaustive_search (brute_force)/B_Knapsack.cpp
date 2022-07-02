#include <bits/stdc++.h>

#define a first
#define c second

using namespace std;

vector<pair<int, int> > v(37);
vector<vector<int> > dp(32, vector<int>(1048576, 0));

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int n, b;

    cin >> n >> b;

    for(int i = 1; i <= n; i++)
        cin >> v[i].a >> v[i].c;

    for(int j = 1; j <= b; j++) {
        for(int i = 1; i <= n; i++) {
            if(v[i].a <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].a] + v[i].c);
            else dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][b];


    return 0;
}