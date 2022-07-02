#include <bits/stdc++.h>

#define inf 10000000
using namespace std;

unsigned int n, tmp, lim;
unsigned int e[22][22];
unsigned int dp[1048600][22];

void solve(){
	for(int mask = 1; mask < lim; mask += 2){
		for(int v = 1; v < n; v++){
			if((mask >> v) & 1){
				int x = mask - (1 << v);
				if(x == 0)
					continue;
				for(int u = 1; u != n; u++){
					if((x >> u) & 1){
						tmp = dp[x][u + 1] + e[u + 1][v + 1];
						
						if(dp[mask][v + 1])
							dp[mask][v + 1] = min(dp[mask][v + 1], tmp);
						else
							dp[mask][v + 1] = tmp;
					}
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(0);

	// freopen("input.txt", "r", stdin);
	int m, ii, jj;

	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			e[i][j] = inf;
	
	for(int i = 0; i != m; i++){
		cin >> ii >> jj;
		cin >> e[ii][jj];
	}
	
	lim = (1 << n);
	
	for(int i = 1; i != n; i++){
		dp[(1 << i) | 1][i + 1] = e[1][i + 1];
	}
	
	solve();
	
	unsigned int ans = inf;
	for(int i = 2; i <= n; i++)
		ans = min(ans, dp[lim - 1][i] + e[i][1]);
	cout << ans;
	return 0;
}