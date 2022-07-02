#include <bits/stdc++.h>
 
using namespace std;
 
struct block {
    int x, y, z;
};
 
block v[100007];
int S[100007];
int aa[3];
 
bool operator<(const block&a, const block&b) {
    return a.x < b.x and a.y < b.y;
}
 
bool cmp(const block&a, const block&b) {
    if(a.x != b.x) return a.x > b.x;
    if(a.y != b.y) return a.y > b.y;
    return a.z > b.z;
}
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t, n;
 
    for(int test = 1; ; test++) {
        n = 0;
        cin >> t;
        if (!t) break;
        for(int i = 0; i < t; i++) {
            cin >> aa[0] >> aa[1] >> aa[2];
            sort(aa, aa + 3);
            do {
                v[n] = block{aa[0], aa[1], aa[2]};
                n++;
            } while(next_permutation(aa, aa + 3));
        }
 
        sort(v, v + n, cmp);
 
        int ans = 0;
 
        for(int i = 0; i < n; ++i) {
            S[i] = v[i].z; 
            for(int j = 0; j < i; ++j) {
                if(v[i] < v[j]) {
                    S[i] = max(S[i], S[j] + v[i].z);
                }
            }
            ans = max(ans, S[i]);
        }
        cout << "Case " << test << ": maximum height = " << ans << '\n';
    }
    return 0; 
}