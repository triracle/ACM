#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 5;

int n, m, a[maxn];

int main() {
    cin >> n;
    cin >> m;

    int va = 0;
    for (int i = 0; i < n; i++) {
	cin >> a[i];
	va = max(va, a[i]);
    }

    int res1 = 0, res2 = 0;
    for (int i = va; i < 11000; i++) {
	int tot = 0;
	for (int j = 0; j < n; j++) {
	    if (i - a[j] > 0) {
		tot += (i - a[j]);
	    }
	}
	if (tot >= m) {
	    res1 = i;
	    break;
	}
    }
    res2 = va + m;

    cout << res1 << ' ' << res2;

    return 0;
}
