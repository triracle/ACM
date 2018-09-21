#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define mp make_pair
#define sz(a) ((int)a.size())
#define fi first
#define se second

const int maxn = 1e3 + 5;
const int mod = 998244353;

int n, m, a[maxn][maxn];
vector<pair<int, pair<int, int>>> vt;
int r, c;

long long power_mod(long long a, long long b) {
    long long res = 1;
    while (b) {
	if (b % 2) res = res * a % mod;
	a = a * a % mod;
	b >>= 1;
    }
    return res;
}

int main() {
    cin >> n >> m;

    rep(i, 0, n) {
	rep(j, 0, m) {
	    scanf("%d", &a[i][j]);
	}
    }

    scanf("%d%d", &r, &c);
    r--; c--;

    vt.pb(mp(a[r][c], mp(r, c)));
    rep(i, 0, n) {
	rep(j, 0, m) {
	    if (a[i][j] < a[r][c]) {
		vt.pb(mp(a[i][j], mp(i, j)));
	    }
	}
    }

    sort(vt.begin(), vt.end());

    long long sumc = 0, sumr = 0;
    long long sumc2 = 0, sumr2 = 0;
    long long queuec = 0, queuer = 0;
    long long queuec2 = 0, queuer2 = 0;
    long long tot = 0, queueTot = 0;
    int cnt = 0, has = 0;
    rep(i, 0, sz(vt)) {
	if (i && vt[i].fi != vt[i - 1].fi) {
	    (tot += queueTot) %= mod;
	    (sumc += queuec) %= mod;
	    (sumr += queuer) %= mod;
	    (sumc2 += queuec2) %= mod;
	    (sumr2 += queuer2) %= mod;
	    has += cnt;
	    queuec = queuer = queuec2 = queuer2 = queueTot = 0;
	    cnt = 0;
	}
	long long tmp = 0;
	tmp += ((long long) vt[i].se.fi * vt[i].se.fi % mod + (long long) vt[i].se.se * vt[i].se.se % mod) * has % mod +
	    sumc2 + sumr2 - 2 * vt[i].se.fi * sumr % mod - 2 * vt[i].se.se * sumc % mod;
	tmp = (tmp + (long long) mod * mod) % mod;
	tmp = (tmp * power_mod(has, mod - 2) % mod);
	tmp = (tmp + tot * power_mod(has, mod - 2)) % mod;
	if (i == sz(vt) - 1) {
	    cout << tmp << '\n';	
	}
	(queueTot += tmp) %= mod;
	(queuer += vt[i].se.fi) %= mod;
	(queuec += vt[i].se.se) %= mod;
	(queuer2 += (long long) vt[i].se.fi * vt[i].se.fi) %= mod;
	(queuec2 += (long long) vt[i].se.se * vt[i].se.se) %= mod;
	cnt++;
    }

    return 0;
}
