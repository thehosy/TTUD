#include <bits/stdc++.h>

using namespace std;

long long n, k;

vector<int> x(10007, 0);
bool mark[10007];

long long temp_fact = 1;

bool in_range(int nt, long long q) {
    temp_fact = 1;
    int i = 1;
    while(i <= nt) {
        temp_fact *= i;
        i++;
        if(temp_fact >= q) {
            return true;
        }
        if(temp_fact > (long long)(1e9))
            return true;
    }
    return false;  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> n >> k;

    // clock_t st = clock();

    if(!in_range(n, k)) {
        cout << -1;
    } else {
        for(int i = 0; i < n; i++)
            x[i] = i + 1;

        for(int i = 0; i < n; i++) { 
            if(in_range(n - i - 1, k)) {
                continue;
            }
            int step = (int) ((k - 1) / temp_fact); 
            int temp = x[i + step];

            for(int j = i + step; j > i; j--) {
                x[j] = x[j - 1];
            }

            x[i] = temp;

            k -= temp_fact * step;
        }
        
        for(int i = 0; i < n; i++)
            cout << x[i] << " ";
    } // 1 5 3 4 5 // 4960 // 640
    // 1 2 3 4 6 12 11 7 9 8 10 5
    // 1 2 3 4 6 5 7 8 9 10 11 12

    // clock_t ed = clock();

    // cout << "\ntime: " << 1.0 * (ed - st) << '\n';
    return 0;
}