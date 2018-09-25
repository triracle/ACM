#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second

const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
pair<int, long long> val[maxn * 20];
int n, a[maxn], q;

void upd(int x, int L, int R, int pos, int v) {
    if (L > pos || pos > R) return;
    if (L == pos && L == R) {
	val[x].fi = (long long) (a[pos] - pos + mod) * v % mod;
	val[x].se = v;
    }

    if (L < R) {
	int M = (L + R) >> 1;
	upd(2 * x, L, M, pos, v);
	upd(2 * x + 1, M + 1, R, pos, v);
	val[x].fi = (val[2 * x].fi + val[2 * x + 1].fi) % mod;
	val[x].se = val[2 * x].se + val[2 * x + 1].se;
    }
}

pair<int, long long> query(int x, int L, int R, int l, int r) {
    if (r < l) return mp(0ll, 0ll);
    if (l > R || L > r) return mp(0ll, 0ll);
    if (l <= L && R <= r) return val[x];
    if (L < R) {
	int M = (L + R) >> 1;
	pair<int, long long> res1 = query(2 * x, L, M, l, r);
	pair<int, long long> res2 = query(2 * x + 1, M + 1, R, l, r);
	return mp((res1.fi + res2.fi) % mod, res1.se + res2.se);
    }
    return mp(0ll, 0ll);
}

int main() {
    scanf("%d%d", &n, &q);

    for (int i = 0; i < n; i++) {
	scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
	int x;
	scanf("%d", &x);
	upd(1, 0, n - 1, i, x);
    }

    for (int i = 0; i < q; i++) {
	int x, y;
	scanf("%d%d", &x, &y);
	if (x < 0) {
	    x = -x;
	    x--;
	    upd(1, 0, n - 1, x, y);
	} else {
	    x--;
	    y--;
	    long long tar = query(1, 0, n - 1, x, y).se;
	    tar /= 2;
	    int l = x, r = y;
	    int found = x - 1;
	    while (l <= r) {
		int mid = (l + r) / 2;
		long long v = query(1, 0, n - 1, x, mid).se;
		if (v <= tar) {
		    found = mid;
		    l = mid + 1;
		} else {
		    r = mid - 1;
		}
	    }
	    found += 1;
	    pair<int, long long> lo, hi;
	    lo = query(1, 0, n - 1, x, found - 1);
	    hi = query(1, 0, n - 1, found + 1, y);
//	    cout << found << ' ' << lo.fi << ' ' << lo.se << ' ' << hi.fi << ' ' << hi.se << endl;
	    long long ans = hi.fi + lo.se % mod * (a[found] - found) % mod - lo.fi - hi.se % mod * (a[found] - found) % mod;
	    ans = (ans + (long long) mod * mod) % mod;
	    ans %= mod;
	    printf("%lld\n", ans);
	}
    }

    return 0;
}
