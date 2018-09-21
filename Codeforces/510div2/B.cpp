#include <bits/stdc++.h>

using namespace std;

#define sz(a) ((int)a.size())

const int oo = 1e9 + 7;

int val[10];
int n;
int x;
string s;

int main() {
    cin >> n;

    for (int i = 0; i < 8; i++) val[i] = oo;
    for (int i = 0; i < n; i++) {
	cin >> x >> s;
	int cur = 0;
	for (int j = 0; j < sz(s); j++) {
	    int res = s[j] - 'A';
	    cur |= (1 << res);
	}
	val[cur] = min(val[cur], x);
    }

    for (int i = 0; i < 10; i++) {
	for (int j = 0; j < 8; j++) {
	    for (int t = 0; t < 8; t++) {
		int cur = (j | t);
		val[cur] = min(val[cur], val[j] + val[t]);
	    }
	}
    }

    cout << (val[7] == oo ? -1 : val[7]);

    return 0;
}
