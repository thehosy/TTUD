#include <bits/stdc++.h>

using namespace std;

vector<int> pre[20];
int c[20];

int n, m;
int ans = INT_MAX;
int temp_ans = 0;
int assign[20]; 
int load[8];

bool feasible(int course, int current_term) {
    for(int j : pre[course]) {
        if (assign[j] == current_term) return false;
    }
    return true;
}

void solve(int course) {
    for(int i = 0; i < m; i++) {
        if (feasible(course, i)) {
            assign[course] = i;
            load[i] += c[course];
            int last = temp_ans;
            temp_ans = max(temp_ans, load[i]);

            if(course == n - 1) ans = min(ans, temp_ans);
            else {
                if(temp_ans < ans) solve(course + 1);
            }
            load[i] -= c[course];
            temp_ans = last;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for(int i = 0, t; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> t;
            if (t) {
                pre[j].push_back(i);
            }
        }
    }

    solve(0);

    cout << ans;

    return 0;
}