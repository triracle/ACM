#include <bits/stdc++.h>

using namespace std;

int n;
int has[200];
char ans[200];
int cnt, dm, vs[200], a[200];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
	cin >> a[i];
	has[a[i]]++;
    }

    for (int i = 1; i <= 100; i++) {
	if (has[i] == 1) {
	    cnt++;
	} else if (has[i] > 2) {
	    dm++;
	}
    }

    if (cnt % 2 && dm == 0) {
	cout << "NO";
	return 0;
    }

    int cur = 0;
    for (int i = 0; i < n; i++) {
	if (has[a[i]] == 1) {
	    vs[i] = 1;
	    ans[i] = (cur ? 'A' : 'B');
	    cur = cur ^ 1;
	}
    }

    if (cnt % 2) {
	for (int i = 0; i < n; i++) {
	    if (has[a[i]] > 2) {
		vs[i] = 1;
		ans[i] = 'A';
		break;
	    }
	}
    }

    for (int i = 0; i < n; i++) {
	if (!vs[i]) {
	    ans[i] = 'B';
	}
    }

    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) cout << ans[i];

    return 0;
}
