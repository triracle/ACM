#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define sz(a) ((int)a.size())
#define pb push_back

const int maxn = 1e6 + 5;

int n, k;
int vs[maxn];
vector<int> adj[maxn];
vector<int> v, e;
int a[maxn];

void dfs(int u) {
    vs[u] = 1;
    e.pb(a[u]);
    v.pb(u);
    for (auto v : adj[u]) {
	if (vs[v]) continue;
	dfs(v);
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
	a[i] = n - i;
    }
    rep(i, 0, k) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--;
	y--;
	adj[x].pb(y);
	adj[y].pb(x);
    }

    rep(i, 0, n) {
	if (!vs[i]) {
	    e.clear();
	    v.clear();
	    dfs(i);
	    sort(e.begin(), e.end());
	    sort(v.begin(), v.end());
	    rep(j, 0, sz(e)) {
		a[v[j]] = e[j];
	    }
	}
    }

    rep(i, 1, n) {
	if (a[i] < a[i - 1]) {
	    cout << "No";
	    return 0;
	}
    }

    cout << "Yes";
    return 0;
}
