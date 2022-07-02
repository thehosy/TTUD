#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;
int A_0[1007];
int A_1[1007];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k1, k2;

    cin >> n >> k1 >> k2;

    A_0[0] = 1;
    A_0[1] = 1;

    for(int i = 2; i <= n; i++){
        A_0[i] = A_1[i - 1];
        for(int j = k1; i - j >=0 and j <= k2; j++){
            A_1[i] += A_0[i - j];
        }
    }

    cout << (A_0[n] % mod + A_1[n] % mod) % mod;

    return 0;
}