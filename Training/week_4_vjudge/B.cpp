#include <bits/stdc++.h>

using namespace std;

bool cmp(const int &n1, const int &n2) {
    return n2 < n1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        int n, d, r;
        cin >> n >> d >> r;
        if (n == 0 && d == 0 && r == 0)
            break;
        int sobh[n + 1], asr[n + 1];
        for (int i = 0; i < n; ++i) {
            cin >> sobh[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> asr[i];
        }
        sort(sobh, sobh + n);
        sort(asr, asr + n, cmp);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (sobh[i] + asr[i] > d)
                ans += sobh[i] + asr[i] - d;
        }

        cout << ans * r << "\n";
    }

    return 0;
}