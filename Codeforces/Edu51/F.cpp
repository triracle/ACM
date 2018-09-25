#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(a) ((int)a.size())

namespace LCA {
    const int maxn = 2e5 + 50;
    const int logn = 20;
    vector<int> events;
    int sta[maxn];
    int tin[maxn];
    int idx[maxn];
    int tms;
    int f[logn][maxn << 1];
    int lg[maxn];
    long long d[maxn];

    void dfs(int u, int p, vector<pair<int, int>> adj[]) {
	if (!~p) d[u] = 0;
        idx[tin[u] = tms++] = u;
        sta[u] = events.size();
        events.push_back(tin[u]);
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].fi;
            if (v != p) {
		d[v] = d[u] + adj[u][i].se;
                dfs(v, u, adj);
                events.push_back(tin[u]);
            }
        }
    }
    int query(int u, int v) {
        int l = u == v ? 0 : lg[v - u];
        return min(f[l][u], f[l][v - (1 << l) + 1]);
    }
    int lca(int u, int v) {
        if (sta[u] > sta[v]) swap(u, v);
        return idx[query(sta[u], sta[v])];
    }
    void build(vector<pair<int, int>> adj[]) {
        events.clear();
        dfs(tms = 0, -1, adj);
        for (int i = 0; i < events.size(); i++) {
            f[0][i] = events[i];
        }
        for (int i = 1; i < logn; i++) {
            for (int j = 0; j + (1 << i - 1) < events.size(); j++) {
                f[i][j] = min(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
            }
        }
        for (int i = 1; i < maxn; i++) {
            lg[i] = __lg(i);
        }
    }
    long long dist(int x, int y) {
	int l = lca(x, y);
	return d[x] - d[l] + d[y] - d[l];
    }
}

const int maxn = 2e5 + 50;

int n, m, q;
int vs[maxn];
vector<pair<int, pair<int, int>>> edge;
map<pair<pair<int, int>, int>, int> has;
vector<pair<int, int>> adj[maxn], nadj[maxn], dadj[maxn];
vector<int> vt;
long long dist[50][50];
int gg[maxn], pos[maxn];
int x[maxn], y[maxn], z[maxn];

void dfsTree(int u) {
    vs[u] = 1;
    for (auto v : adj[u]) {
	if (!vs[v.fi]) {
	    edge.pb(mp(u, v));
	    dfsTree(v.fi);
	    has[mp(mp(min(u, v.fi), max(v.fi, u)), v.se)] = 1;
	}
    }
}

int main() {
    scanf("%d%d", &n, &m);

    rep(i, 0, m) {
	scanf("%d%d%d", &x[i], &y[i], &z[i]);
	x[i]--; y[i]--;
	if (x[i] > y[i]) swap(x[i], y[i]);
	adj[x[i]].pb(mp(y[i], z[i]));
	adj[y[i]].pb(mp(x[i], z[i]));
    }

    dfsTree(0);

    for (auto v : edge) {
	nadj[v.fi].pb(v.se);
    }

    LCA::build(nadj);

    // build max 40 ver graph
    rep(i, 0, m) {
	if (!has.count(mp(mp(x[i], y[i]), z[i]))) {
	    gg[x[i]] = 1;
	    gg[y[i]] = 1;
	    dadj[x[i]].pb(mp(y[i], z[i]));
	    dadj[y[i]].pb(mp(x[i], z[i]));
	}
    }

    rep(i, 0, n) {
	if (gg[i]) {
	    vt.pb(i);
	    pos[i] = sz(vt) - 1;
	}
    }
    
    if (sz(vt) > 40) return 0;

    rep(i, 0, sz(vt)) {
	rep(j, 0, sz(vt)) {
	    dist[i][j] = 1e17;
	}
	dist[i][i] = 0;
    }

    for (auto u : vt) {
	for (auto v : dadj[u]) {
	    dist[pos[u]][pos[v.fi]] = v.se;
	}
    }

    for (auto u : vt) {
	for (auto v : vt) {
	    dist[pos[u]][pos[v]] = min(dist[pos[u]][pos[v]], LCA::dist(u, v));
	}
    }

    for (int k = 0; k < sz(vt); k++) {
	for (int i = 0; i < sz(vt); i++) {
	    for (int j = 0; j < sz(vt); j++) {
		if (dist[i][j] > dist[i][k] + dist[k][j]) {
		    dist[i][j] = dist[i][k] + dist[k][j];
		}
	    }
	}
    }

    // Solve query
    scanf("%d", &q);

    rep(i, 0, q) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	long long ans = LCA::dist(x, y);
	rep(i, 0, sz(vt)) {
	    long long res = LCA::dist(x, vt[i]);
	    rep(j, 0, sz(vt)) {
		long long cur = res + dist[i][j];
		cur += LCA::dist(vt[j], y);
		ans = min(ans, cur);
	    }
	}
	printf("%lld\n", ans);
    }

    return 0;
}
