#include <bits/stdc++.h>

using namespace std;

#define sz(a) ((int)a.size())

int isU(char c) {
    return 'A' <= c && c <= 'Z';
}

int isL(char c) {
    return 'a' <= c && c <= 'z';
}

int isD(char c) {
    return '0' <= c && c <= '9';
}

int main() {
    int T;
    cin >> T;

    while (T--) {
	string s;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	cin >> s;
	for (int i = 0; i < sz(s); i++) {
	    if (isL(s[i])) cnt1++;
	    if (isU(s[i])) cnt2++;
	    if (isD(s[i])) cnt3++;
	}
	if (cnt1 && cnt2 && cnt3) {
	} else if (!cnt1 && !cnt2 && cnt3) {
	    s[0] = 'a';
	    s[1] = 'A';
	} else if (!cnt1 && cnt2 && !cnt3) {
	    s[0] = 'a';
	    s[1] = '0';
	} else if (cnt1 && !cnt2 && !cnt3) {
	    s[0] = 'A';
	    s[1] = '0';
	} else if (cnt1 && cnt2 && !cnt3) {
	    for (int i = 0; i < sz(s); i++) {
		if (cnt1 > cnt2) {
		    if (isL(s[i])) {
			s[i] = '0';
			break;
		    }
		} else {
		    if (isU(s[i])) {
			s[i] = '0';
			break;
		    }	
		}
	    }
	} else if (!cnt1 && cnt2 && cnt3) {
	    for (int i = 0; i < sz(s); i++) {
		if (cnt2 > cnt3) {
		    if (isU(s[i])) {
			s[i] = 'a';
			break;
		    }
		} else {
		    if (isD(s[i])) {
			s[i] = 'a';
			break;
		    }
		}
	    }
	} else if (cnt1 && !cnt2 && cnt3) {
	    for (int i = 0; i < sz(s); i++) {
		if (cnt1 > cnt3) {
		    if (isL(s[i])) {
			s[i] = 'A';
			break;
		    }
		} else {
		    if (isD(s[i])) {
			s[i] = 'A';
			break;
		    }
		}
	    }
	}

	cout << s << '\n';
    }

    return 0;
}
