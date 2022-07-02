
#include <bits/stdc++.h>
 
using namespace std;
 
int arr[1000001];
int n;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int temp = arr[0];
    int ans = arr[0];
    
    for(int i = 1; i < n; i++) {
        if(temp <= 0) {
            temp = arr[i];
        } else temp += arr[i];
        ans = max(ans, temp);
    }
    
    cout << ans;
    
    return 0;
}