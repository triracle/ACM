#include <bits/stdc++.h>

using namespace std;

#define sz(a) ((int)a.size())
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int maxn = 20;

int n;
int vs[maxn];
vector<pair<pair<int, int>, int>> ans;

int main() {
	cin >> n;
	
	int pos = -1;
	for (int i = 0; i < 20; i++) {
		if ((n & (1 << i)) != 0) {
			vs[i] = 1;
			pos = i;
		}
	}

	int totv = pos + 1;

	for (int i = 0; i < pos; i++) {
		int val = (1 << (pos - 1 - i));
		ans.pb(mp(mp(i + 1, i + 2), 0));
		ans.pb(mp(mp(i + 1, i + 2), val));
	}

	int cur = (1 << pos);
	for (int i = pos - 1; i >= 0; i--) {
		if (vs[i]) {
			int dis = pos - i;
			ans.pb(mp(mp(1, dis + 1), cur));
			cur += (1 << i);
		}
	}

	cout << totv << ' ' << sz(ans) << '\n';
	for (auto ed : ans) {
		cout << ed.fi.fi << ' ' << ed.fi.se << ' ' << ed.se << '\n';
	}

	return 0;
}
