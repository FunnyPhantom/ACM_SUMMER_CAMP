//
// Created by Mohamad on 8/5/2018.
//

#include <bits/stdc++.h>

using namespace std;
#define ll long long


const int max_nk = 1003;
ll dp[max_nk][max_nk];
ll peymane = 1e9 + 7;

void init() {
    for (int i = 0; i < max_nk; ++i) {
        for (int j = 0; j < max_nk; ++j) {
            dp[i][j] = -1;
        }
    }
}


long long entekhab(int n, int k) {
    if (n <= 0) return 0;
    if (k == 1) return n;
    if (n == k) return 1;
    if (k > n) return 0;


    if (dp[n][k] != -1) return dp[n][k];
    dp[n][k] = (entekhab(n - 1, k - 1) + entekhab(n - 1, k)) % peymane;
    return dp[n][k];
}


int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    init();
    cout << entekhab(n, k) << endl;

    return 0;
}