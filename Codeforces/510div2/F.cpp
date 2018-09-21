#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define sz(a) ((int)a.size())

const int maxn = 1e6 + 5;
vector<int> adj[maxn];
int val[maxn];
int n, k, ans;

void dfs(int u, int p) {
    int leaf = 1;
    for (auto v : adj[u]) {
	if (v == p) continue;
	leaf = 0;
	dfs(v, u);
    }
    if (leaf) {
	val[u] = 0;
    } else {
	vector<int> vt;
	for (auto v : adj[u]) {
	    if (v == p) continue;
	    if (val[v] + 1 < k) {
		vt.pb(val[v] + 1);
	    }
	}
	if (sz(vt) == 0) {
	    val[u] = 1e9;
	    return;
	}
	sort(vt.begin(), vt.end());
	int now = 0;
	val[u] = vt[0];
	rep(i, 1, sz(vt)) {
	    if (val[u] + vt[i] <= k) {
		ans--;
		val[u] = vt[i];
	    }
	}
    }
}

int main() {
    cin >> n >> k;

    rep(i, 0, n - 1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--;
	y--;
	adj[x].pb(y);
	adj[y].pb(x);
    }

    rep(i, 0, n) {
	if (sz(adj[i]) == 1) ans++;
    }

    rep(i, 0, n) {
	if (sz(adj[i]) > 1) {
	    dfs(i, i);
	    break;
	}
    }

    cout << ans;

    return 0;
}
