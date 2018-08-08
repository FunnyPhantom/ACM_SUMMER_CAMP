//
// Created by Mohamad on 8/5/2018.
//

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1e3;

constexpr int max_k(int max_n) { return 20 * max_n; }

int n, k;
int g[max_n];
int h[max_n];

int dp[max_n][max_k(max_n)];

int f(int rem, int i) {
    if (rem < 0) return INT_MIN;
    if (i < 0) return 0;
    if (dp[rem][i] != 0) return dp[rem][i];
    dp[rem][i] = max(f(rem, i - 1), f(rem - g[i], i - 1) + h[i]);
    return dp[rem][i];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int gi, hi;
        cin >> gi >> hi;
        if (gi >= 10) {
            n--;
            continue;
        }
        g[i] = 10 - gi;
        h[i] = hi;
    }
    if (k >= max_k(n)) {
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            counter += h[i];
        }
        cout << counter << endl;
        exit(0);
    }

    memset(dp, -1, sizeof(dp));
    int ans = f(k, n - 1);
    cout << ans << endl;


    return 0;
}