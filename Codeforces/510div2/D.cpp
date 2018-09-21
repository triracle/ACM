#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define fi first
#define se second

const int maxn = 2e5 + 5;

int n;
long long k;
long long s[maxn], a[maxn], fen[maxn * 2];
map<long long, int> mm;

void updateBIT(int u) {
    while (u) {
	fen[u]++;
	u -= (u & -u);
    }
}

long long getBIT(int u) {
    long long res = 0;
    while (u < maxn * 2) {
	res += fen[u];
	u += (u & -u);
    }
    return res;
}

int main() {
    cin >> n >> k;

    rep(i, 0, n) cin >> a[i];

    s[0] = a[0];

    rep(i, 1, n) s[i] = a[i] + s[i - 1];

    rep(i, 0, n) {
	mm[s[i]] = 1;
	mm[s[i] - k] = 1;
    }

    int cnt = 0;
    for (auto it = mm.begin(); it != mm.end(); it++) {
	it->se = ++cnt;
    }

    long long ans = 0;
    rep(i, 0, n) {
	long long now = s[i] - k;
	ans += getBIT(mm[now] + 1);
	updateBIT(mm[s[i]]);
	ans += (s[i] < k);
    }

    cout << ans;

    return 0;
}
