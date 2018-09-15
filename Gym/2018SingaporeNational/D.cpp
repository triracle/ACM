#include <bits/stdc++.h>

using namespace std;

#define sz(a) ((int)a.size())
#define pb push_back
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define mp make_pair

const int MAXN = 1e5 + 5;

int Low[MAXN], Num[MAXN], n, T, cau, has[MAXN], m;
vector<int> adj[MAXN];
int ans = 0;
int vs[MAXN];
int N;
map<pair<int, int>, int> mm, edge;

void dfs(int u, int p) {
	int cnt = 0;
	Low[u] = Num[u] = ++T;
	for (int i=0; i<sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v != p) {
			if (Num[v] != 0) {
				Low[u] = min(Low[u], Num[v]);
			}
			else {
				dfs(v, u);
				cnt++;
				Low[u] = min(Low[u], Low[v]);
				
				if (Low[v] >= Num[v]) {
				    cau++;
				    mm[mp(min(u, v), max(u, v))] = 1;
				}
				
				if (u == p) {
					if (cnt >= 2) has[u] = 1;
				}
				else {
					if (Low[v] >= Num[u]) has[u] = 1;
				}
			}
		}
	}
}

int check(int u, int v) {
    if (u > v) swap(u, v);
    if (mm.count(mp(u, v))) return 0;
    return 1;
}

void dfs(int u) {
    vs[u] = 1;
    if (u < N) ans++;
    for (auto v : adj[u]) {
	if (check(u, v) && !vs[v]) {
	    dfs(v);
	}
    }
}

int main() {
    cin >> n >> m;
    N = n;

    rep(i, 0, m) {
	int x, y;
	scanf("%d%d", &x, &y);
	if (x > y) swap(x, y);
	if (edge.count(mp(x, y))) {
	    n++;
	    adj[x].pb(n - 1);
	    adj[n - 1].pb(x);
	    adj[y].pb(n - 1);
	    adj[n - 1].pb(y);
	    continue;
	}
	adj[x].pb(y);
	adj[y].pb(x);
	edge[mp(x, y)] = 1;
    }

    for (int i = 0; i < n; i++) {
	if (Num[i] == 0) dfs(i, i);
    }

    dfs(0);

    cout << ans;

    return 0;
}
