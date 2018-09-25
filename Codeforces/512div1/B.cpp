#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;

int n;
int a[maxn];
int has[maxn][2];
int pos[maxn];

int cntBit(long long a) {
    int res = 0;
    for (int i = 0; i < 62; i++) {
	if (((1ll << i) & a) != 0) res++;
    }
    return res;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
	long long x;
	cin >> x;
	a[i] = cntBit(x);
    }

    int cur = 0;
    for (int i = 0; i < n; i++) {
	cur = (cur + a[i]) % 2;
	if (i) {
	    has[i][0] = has[i - 1][0];
	    has[i][1] = has[i - 1][1];
	}
	pos[i] = cur;
	has[i][cur]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
	int tot = 0;
	int val = 0;
	int pre = (i ? pos[i - 1] : 0);
	for (int j = i; j < n; j++) {
	    if (tot > 120) {
		ans += (has[n - 1][pre] - has[j - 1][pre]);
		break;
	    }
	    tot += a[j];
	    val = max(val, a[j]);
	    if (tot - val >= val && tot % 2 == 0) {
//		cout << i << ' ' << j << endl;
		ans++;
	    }
	}
    }

    cout << ans;

    return 0;
}
