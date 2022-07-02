#include <bits/stdc++.h>

using namespace std;

struct point {
    int id;
    int x, y;
};

struct solution {
    int min_id;
    int max_id;
    double dist;
};

bool cmp(const point&a, const point&b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int n;
point p[50007];
point temp[50007];

inline double norm2(const point &a, const point&b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

solution naive_compute(int first, int last) {
    solution sol = solution{0, 0, INT_MAX};
    for(int i = first; i < last; i++) {
        for(int j = i + 1; j < last; j++) {
            double d = norm2(p[i], p[j]);
            if(sol.dist > d){
                sol.min_id = p[i].id;
                sol.max_id = p[j].id;
                sol.dist = d;
            }
        }
    }
    return sol;
}

solution solve(int first, int last) {
    if (last - first < 5) {
        return naive_compute(first, last);
    }

    int mid = (last + first) >> 1;

    solution left_distance = solve(first, mid);
    solution right_distance = solve(mid, last);
    solution feasible_result = left_distance.dist < right_distance.dist? left_distance: right_distance;
    int t = 0;
    int ti = first;
    while(ti < last && p[mid].x - p[ti].x >= feasible_result.dist) ti++;
    while(ti < last && p[ti].x - p[mid].x < feasible_result.dist) {
        temp[t++] = p[ti++];
    }

    for(int i = 0; i < t; i++) {
        for(int j = i + 1; j < t; j++) {
            double d = norm2(temp[i], temp[j]);
            if(d < feasible_result.dist) {
                feasible_result.min_id = temp[i].id;
                feasible_result.max_id = temp[j].id;
                feasible_result.dist = d;
            }
        }
    }
    return feasible_result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }

    sort(p, p + n, cmp);

    auto f = solve(0, n);

    printf("%d %d %.6lf", min(f.min_id, f.max_id), max(f.max_id, f.min_id), f.dist);

    return 0;
}