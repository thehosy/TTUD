#include<bits/stdc++.h>

using namespace std;

int arr[100007];
int n, L1, L2;
int res;

void solve(){
    res = arr[0];
    for(int i = 1; i != n; i++){
        int temp = 0;
        for(int j = i - L2; j <= i - L1; j++){
            if(j >= 0){
                temp = max(temp, arr[j]);
            }
        }
        arr[i] = temp + arr[i];
        res = max(res, arr[i]);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> L1 >> L2;
	for(int i = 0; i != n; i++)
		cin >> arr[i];

    solve();

    cout << res;
}