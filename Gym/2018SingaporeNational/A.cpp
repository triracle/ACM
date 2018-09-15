#include <bits/stdc++.h>

using namespace std;

#define sz(a) ((int)a.size())

int dx[] = {1, -1, 1, -1, 2, -2, 2, -2};
int dy[] = {2, -2, -2, 2, 1, -1, -1, 1};
const string l = "ICPCASIASG";

int n;
string s;
int vs[101][10101];

int check(int pos, int cur) {
    if (~vs[pos][cur]) return vs[pos][cur];
    if (pos == sz(l) - 1) return 1;
    int xc = cur / n;
    int yc = cur % n;
    int res = 0;
    for (int i = 0; i < 8; i++) {
	for (int j = 0; j < 8; j++) {
	    int xn = xc + dx[i];
	    int yn = yc + dy[i];
	    if (xn < 0 || xn >= n || yn < 0 || yn >= n) continue;
	    int now = xn * n + yn;
	    if (s[now] == l[pos + 1]) res |= check(pos + 1, now);
	}
    }
    return vs[pos][cur] = res;
} 

int main() {
    cin >> n;
    cin >> s;

    for (int i = 0; i < 101; i++) {
	for (int j = 0; j < 10001; j++) {
	    vs[i][j] = -1;
	}
    }

    for (int i = 0; i < sz(s); i++) {
	if (s[i] == 'I') {
	    if (check(0, i)) {
		cout << "YES";
		return 0;
	    }
	}
    }

    cout << "NO";

    return 0;
}
