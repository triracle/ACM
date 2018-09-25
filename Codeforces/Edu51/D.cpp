#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)

const int mod = 998244353;

const int maxn = 1e3 + 5;

int n, k;
long long dp[maxn][4][maxn * 2];

int main() {
    cin >> n >> k;

    dp[0][0][1] = 1;
    dp[0][1][2] = 1;
    dp[0][2][2] = 1;
    dp[0][3][1] = 1;

    rep(i, 1, n) {
	rep(j, 0, 4) {
	    int xj = j % 2;
	    int yj = j / 2;
	    rep(t, 0, 4) {
		int xt = t % 2;
		int yt = t / 2;
		int tar = 0;
		if (xt != xj && yt != yj) {
		    if (xj != yj) tar = 2;
		    else tar = 1;
		} else {
		    if (xt == xj && yt != yj) {
			if (xj != yj) tar = 1;
		    } else if (xt != xj && yt == yj) {
			if (xj != yj) tar = 1;
		    }
		}
		rep(m, 1, k + 1 - tar) {
		    (dp[i][j][m + tar] += dp[i - 1][t][m]) %= mod;
		}
	    }
	}
    }

    long long ans = 0;
    rep(i, 0, 4) {
	ans += dp[n - 1][i][k];
    }
    ans %= mod;

    cout << ans;

    return 0;
}
