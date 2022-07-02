#include <bits/stdc++.h>

using namespace std;

unsigned int n, l;
int lantern[1024];

bool check(double mid) {
    double maxL = 0, minL = l;

    for(int i = 0; i < n; i++) {
        double u = lantern[i] - mid;
        double d = lantern[i] + mid;
        if (u > maxL) return false;
        maxL = max(maxL, d);
    }    

    for(int i = n - 1; i >= 0; i--) {
        double u = lantern[i] - mid;
        double d = lantern[i] + mid;
        if (d < minL) return false;
        minL = min(minL, u);
    }   

    return maxL >= l and minL <= 0;
}

void solve(){
    double lo = 0;
    double hi = l;
    double ans = l + 1;

    for(int _ = 0; _ < 300; ++_) {
        double mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
            ans = mid;
        } else {
            lo = mid;
        }
        // printf("mid = %.10lf, lo = %.10lf, hi = %.10lf, diff = %.10lf\n", mid, lo, hi, abs(lo - hi));
    }   

    printf("%.10lf", ans);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("out.txt", "w", stdout);


    cin >> n >> l;

    for(int i = 0; i < n; i++){
        cin >> lantern[i];
    }
    sort(lantern, lantern + n);
    solve();

    return 0;
}