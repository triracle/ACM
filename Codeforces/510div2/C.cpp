#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define mp make_pair
#define fi first
#define se second
#define sz(a) ((int)a.size())
#define pb push_back

const int maxn = 2e5 + 5;

int n, a[maxn];
vector<int> st[3];
vector<pair<int, int>> ans;

int main() {
    cin >> n;

    rep(i, 0, n) cin >> a[i];

    rep(i, 0, n) {
	if (a[i] == 0) st[0].pb(i);
	if (a[i] < 0) st[1].pb(i);
	if (a[i] > 0) st[2].pb(i);
    }

    if ((sz(st[1]) == 1 && sz(st[2]) == 0) || (sz(st[0]) == n)) {
	for (int i = 0; i < n - 1; i++) {
	    printf("%d %d %d\n", 1, i + 1, i + 2);
	}
	return 0;
    }

    int pos = -1;

    if (sz(st[1]) % 2) {
	rep(i, 0, sz(st[1])) {
	    if (!~pos || a[st[1][i]] > a[pos]) {
		pos = st[1][i];
	    }
	}
    }

    int pre1 = -1;

    for (auto v : st[1]) {
	if (~pre1) {
	    if (v != pos) {
		ans.pb(mp(pre1, v));
	    }
	}
	if (v != pos) pre1 = v;
    }

    int pre0 = -1;
    for (auto v : st[0]) {
	if (~pre0) {
	    ans.pb(mp(pre0, v));
	}
	pre0 = v;
    }

    if (~pre0 && ~pos) {
	ans.pb(mp(pre0, pos));
    }

    int pre2 = -1;
    for (auto v : st[2]) {
	if (~pre2) {
	    ans.pb(mp(pre2, v));
	}
	pre2 = v;
    }

    if (~pre1 && ~pre2) {
	ans.pb(mp(pre1, pre2));
    }

    for (auto res : ans) {
	printf("%d %d %d\n", 1, res.fi + 1, res.se + 1);
    }

    if (~pos && ~pre0) {
	printf("%d %d\n", 2, pos + 1);
    } else if (~pos) {
	printf("%d %d\n", 2, pos + 1);
    } else if (~pre0) {
	printf("%d %d\n", 2, pre0 + 1);
    }

    return 0;
}
