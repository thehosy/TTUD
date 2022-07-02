#include <bits/stdc++.h>

using namespace std;

int W, H, N;
int dp[607][607];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> W >> H >> N;
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			dp[i][j] = i * j;

	for (int i = 0, w, h; i < N; i++) {
		cin >> w >> h;
		dp[h][w] = 0;
	}

    for (int h = 1; h <= H; h++) {
		for (int w = 1; w <= W; w++) {
			for (int i = 1; i < h; i++)
				dp[h][w] = min(dp[h][w], dp[i][w] + dp[h - i][w]);
			for (int j = 1; j < w; j++)
				dp[h][w] = min(dp[h][w], dp[h][j] + dp[h][w - j]);
		}
    }
	cout << dp[H][W];

    return 0;
}