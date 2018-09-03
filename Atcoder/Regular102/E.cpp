#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e3 + 3;
const int mod = 998244353;

int k, n;
long long po2[maxn];
long long C[maxn][maxn];
long long has[maxn];

int main() {
	cin >> k >> n;
	
	po2[0] = 1;
	for (int i = 1; i < maxn; i++) {
		po2[i] = po2[i - 1] * 2 % mod;
	}
	for (int i = 0; i < maxn; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
	}

	for (int i = 0; i <= k / 2; i++) {
		int rem = k - i * 2;
		for (int j = 0; j <= i; j++) {
			int tot = j + rem;
			if (n - 2 - j < 0) continue;
			long long res = po2[j] * C[i][j] % mod * C[n - 2 - j + tot - 1][n - 2 - j] % mod;
			has[i] += res;
			has[i] %= mod;
		}
	}

	for (int i = 2; i <= 2 * k; i++) {
		int cnt = 0;
		int tar = min(k, i);
		for (int j = 1; j <= tar; j++) {
			int t = i - j;
			if (t < j) break;
			if (t <= k) cnt++;
		}
		long long res = 0;
		for (int j = 0; j < cnt; j++) {
			res += has[j];
			res %= mod;
		}
		res = C[n + k - 1][n] - res;
		if (res < 0) res += mod;
		cout << res << '\n';
	}

	return 0;
}
