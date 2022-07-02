#include <bits/stdc++.h>

using namespace std;

int a[1048576];
int Sl[1048576];
int Sc[1048576];
bool checkEven[1048576];
bool checkOdd[1048576];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(a[0] & 1) {
        checkOdd[0] = true;
        Sl[0] = a[0];
    } else {
        checkEven[0] = true;
        Sc[0] = a[0];
    }

    for(int i = 1; i < n; i++) {
        if(a[i] & 1) {
            if(checkEven[i - 1] && Sc[i - 1] > 0) {
                Sl[i] = Sc[i - 1] + a[i];
            } else {
                Sl[i] = a[i];
            }
            checkOdd[i] = true;


            if(checkOdd[i - 1]) {
                Sc[i] = Sl[i - 1] + a[i];
                checkEven[i] = true;
            }

        } else {
            if(checkEven[i - 1] && Sc[i - 1] > 0) {
                Sc[i] = Sc[i - 1] + a[i];
            } else {
                Sc[i] = a[i];
            }
            checkEven[i] = true;

            if(checkOdd[i - 1]) {
                checkOdd[i] = true;
                Sl[i] = Sl[i - 1] + a[i];
            }
        }
    }
    int ans = -1000001;

    for(int i = 0; i < n; i++) {
        if(checkEven[i])
            ans = max(ans, Sc[i]);
    }

    (ans & 1)? cout << "NOT_FOUND" : cout << ans;

    return 0;
}