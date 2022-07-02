#include<iostream>

#define INF 10000000

using namespace std;

int n, m, cm = INF, res = INF, temp = 0, l;
bool mark[32];
int f[32][32];
int x[32];
int w = 0;

void Try(int id){
    for(int v = 1; v < l; ++v){
        if(!mark[v]){
            if(v <= n) w += 1;
            else w -= 1;
            x[id] = v;
            temp += f[x[id - 1]][x[id]];
            mark[v] = true;
            if(id == l - 1 and w == 0){
                if(res > temp + f[x[l - 1]][x[0]]) {
                    for(int ii = 0; ii < l; ++ii)
                    cout << x[ii] << ' ';
                
                cout << '\n';
                }
                res = min(res, temp + f[x[l - 1]][x[0]]);
            }
            else {
                int dk = temp + cm * (l - id);
                if(dk < res)
                    Try(id + 1);
            }
            temp -= f[x[id - 1]][x[id]];
            mark[v] = false;
            if(v <= n) w -= 1;
            else w += 1;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n;
    
    l = (n << 1 | 1);
    
    for(int i = 0; i < l; ++i){
        for(int j = 0; j < l; ++j) {
            cin >> f[i][j];
            if(i != j) cm = min(cm, f[i][j]);
        }
    }
    mark[0] = true;
    x[0] = 0;
    Try(1);
    cout << res;
    return 0;
}