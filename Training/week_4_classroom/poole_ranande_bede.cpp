//
// Created by Mohamad on 8/5/2018.
//
#include <bits/stdc++.h>

using namespace std;

const int max_n = 1e4, max_seke = 1e3;
const int minusinf = INT_MIN;
int sekkes[max_seke + 10];

int dp[max_n][max_seke];


int f(int r, int i) {
    if (r < 0) return minusinf;
    if (i < 0) {
        if (r == 0) return 0;
        return minusinf;
    }
    if (dp[r][i] != -1) return dp[r][i];
    dp[r][i] = max(f(r, i - 1), f(r - sekkes[i], i - 1) + 1);
    return dp[r][i];
}

using namespace std;

int main() {
    memset(dp, -1, sizeof(dp));
    int n, n_s;
    cin >> n_s >> n;
    for (int i = 0; i < n_s; i++) {
        cin >> sekkes[i];
    }
    int ans = f(n, n_s - 1);
    cout << (ans > 0 ? to_string(ans) : "No Way!") << endl;
}

